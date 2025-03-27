#include <mandelbrot.h>

#include <stdlib.h>
#include <math.h>

mdContext_t mdContextCtor(int WIDTH, int HEIGHT) {
    mdContext_t context = { .screen  = (uint32_t *) calloc(WIDTH*HEIGHT, sizeof(uint32_t)),
                            .escapeN = (uint32_t *) calloc(WIDTH*HEIGHT, sizeof(uint32_t)),
                            .WIDTH   = WIDTH,        .HEIGHT  = HEIGHT,
                            .centerX = MD_DEFAULT_X, .centerY = MD_DEFAULT_Y,
                            .scale = MD_DEFAULT_PLANE_WIDTH / WIDTH};

    return context;
}

int mdContextDtor(mdContext_t *context) {
    free(context->screen);
    free(context->escapeN);
    return 0;
}

/// @brief Get 32-bit rgba color from r,g,b
inline uint32_t generateColor(int r, int g, int b) {
    // SFML uses rgba
    return (r << 0) + (g << 8) + (b << 16) + (255 << 24);
}

int calculateMandelbrot(const mdContext_t md) {
    /*Unpacking values from mdContext_t for convinience */
    uint32_t *escapeN = md.escapeN; 
    const md_float centerX = md.centerX, centerY = md.centerY;
    const md_float scale = md.scale;
    const int WIDTH = md.WIDTH, HEIGHT = md.HEIGHT;

    /*Points never come back after ESCAPE_RADIUS*/
    const md_float ESCAPE_RADIUS2 = MD_ESCAPE_RADIUS * MD_ESCAPE_RADIUS;

    /*Main loop*/
    for (int iy = 0; iy < HEIGHT; iy++) {
        /*Calculating position of the pixel with coordinates (ix, iy)*/
        md_float x0 = centerX - scale * WIDTH / 2,
                 y0 = centerY + (HEIGHT/2 - iy) * scale;
        md_float dx = scale;

        for (int ix = 0; ix < WIDTH; ix++, x0 += dx) {
            /*
                z' = z^2 + z_0 = (x+iy)^2 + x_0 + iy_0 = x^2 - y^2 + x_0 + i(2x*y + y_0)
                x' = x^2 - y^2 + x0
                y' = 2xy + y_0
            */
            md_float x = x0, y = y0;

            int iter = 0;
            for (; iter < MD_MAX_ITER; iter++) {
                md_float x2   = x * x, 
                         y2   = y * y,
                         xy_2 = x * y * 2.0;

                if (x2 + y2 > ESCAPE_RADIUS2)
                    break;

                x = x2 - y2 + x0;
                y = xy_2    + y0;
            }

            escapeN[iy * WIDTH + ix] = iter;
        }
    }
    return 0;
}

#include <immintrin.h>

const int PACKED_SIZE = 128/8 / sizeof(md_float);
typedef md_float pmd_float[PACKED_SIZE];
typedef int   pcmp[PACKED_SIZE]; // packed cmp array


inline void pmd_float_add(pmd_float res, const pmd_float a, const pmd_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) res[i] = a[i] + b[i];
}

inline void pmd_float_sub(pmd_float res, const pmd_float a, const pmd_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) res[i] = a[i] - b[i];
}

inline void pmd_float_mul(pmd_float res, const pmd_float a, const pmd_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) res[i] = a[i] * b[i];
}

inline void pmd_float_cmp(int *cmp, const pmd_float a, const md_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) cmp[i] = a[i] < b;
}

inline void pmd_float_set(pmd_float a, const md_float v) {
    for (int i = 0; i < PACKED_SIZE; i++) a[i] = v;
}

inline void pmd_float_copy(pmd_float a, const pmd_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) a[i] = b[i];
}

int calculateMandelbrotOptimized(const mdContext_t md) {

    /*Unpacking values from mdContext_t for convinience */
    uint32_t *escapeN = md.escapeN; 
    const md_float centerX = md.centerX, centerY = md.centerY;
    const md_float scale = md.scale;
    const int WIDTH = md.WIDTH, HEIGHT = md.HEIGHT;

    /*Points never come back after ESCAPE_RADIUS*/
    const md_float ESCAPE_RADIUS2 = MD_ESCAPE_RADIUS * MD_ESCAPE_RADIUS;

    md_float dx = scale;
    alignas(16) pmd_float initDelta__;
    for (int i = 0; i < PACKED_SIZE; i++) {
        initDelta__[i] = scale * i;
    }
    __m128 initDelta = _mm_load_ps(initDelta__);

    for (int iy = 0; iy < HEIGHT; iy++) {
//
//         md_float x0 = centerX - scale * WIDTH / 2,
//                  y0 = centerY + (HEIGHT/2 - iy) * scale;

        __m128 y0 = _mm_set_ps1(centerY + (HEIGHT / 2 - iy) * scale);
        // pmd_float_set(y0, centerY + (HEIGHT/2 - iy) * scale);
        for (int ix = 0; ix < WIDTH; ix+= PACKED_SIZE) {
            __m128 x0 = _mm_set_ps1(centerX - scale*WIDTH / 2 + ix * scale);
            x0 = _mm_add_ps(x0, initDelta);

            /*
                z' = z^2 + z_0 = (x+iy)^2 + x_0 + iy_0 = x^2 - y^2 + x_0 + i(2x*y + y_0)
                x' = x^2 - y^2 + x0
                y' = 2xy + y_0
            */
            __m128 x = x0;
            __m128 y = y0;

            // int iter[PACKED_SIZE] = {0};
            int iter[PACKED_SIZE] = {0};

            for (int i = 0; i < MD_MAX_ITER; i++) {
                __m128 x2   = _mm_mul_ps(x, x);
                __m128 y2   = _mm_mul_ps(y, y);
                __m128 xy_2 = _mm_mul_ps(x, y);
                xy_2 = _mm_add_ps(xy_2, xy_2);
                // md_float x2 = x*x, y2 = y*y, xy_2 = 2*x*y;

                __m128 r2 = _mm_add_ps(x2, y2);
                
                __m128 escapeR2 = _mm_set_ps1(ESCAPE_RADIUS2);
                __m128 cmp = _mm_cmple_ps(r2, escapeR2);
                int mask = _mm_movemask_ps(cmp);

                if (!mask) break;

                for (int j = 0; j < PACKED_SIZE; j++) {
                    iter[j] += mask & 1;
                    mask >>= 1;
                }

                x = _mm_sub_ps(x2,y2);
                x = _mm_add_ps(x, x0);

                y = _mm_add_ps(xy_2, y0);
                // x = x2 - y2 + x0;
                // y = xy_2    + y0;
            }


            for (int i = 0; i < PACKED_SIZE; i++) {
                escapeN[iy*WIDTH + ix + i] = iter[i];
            }
        }
    }


    return 0;

}


int convertItersToColor(const mdContext_t md) {
    for (int idx = 0; idx < md.WIDTH * md.HEIGHT; idx++) {
        int iter = md.escapeN[idx];

        if (iter == MD_MAX_ITER)
            md.screen[idx] = 0; // Black 
        else {
            uint8_t red   = MD_MAX_ITER - iter;
            uint8_t green = 95*(1+sin(sqrt(iter)/1.1));
            uint8_t blue  = 40. * logf(iter);

            md.screen[idx] = generateColor(red, green, blue);
        }

    }

    return 0;
}
