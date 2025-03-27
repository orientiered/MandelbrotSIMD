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

const int PACKED_SIZE = 128/8 / sizeof(md_float);
typedef md_float pmd_float[PACKED_SIZE];
typedef int   pcmp[PACKED_SIZE]; // packed cmp array

static inline void pmd_float_add(pmd_float res, const pmd_float a, const pmd_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) res[i] = a[i] + b[i];
}

static inline void pmd_float_sub(pmd_float res, const pmd_float a, const pmd_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) res[i] = a[i] - b[i];
}

static inline void pmd_float_mul(pmd_float res, const pmd_float a, const pmd_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) res[i] = a[i] * b[i];
}

static inline void pmd_float_cmp(int *cmp, const pmd_float a, const md_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) cmp[i] = a[i] < b;
}

static inline void pmd_float_set(pmd_float a, const md_float v) {
    for (int i = 0; i < PACKED_SIZE; i++) a[i] = v;
}

static inline void pmd_float_copy(pmd_float a, const pmd_float b) {
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
    pmd_float initDelta = {0};
    for (int i = 0; i < PACKED_SIZE; i++) {
        initDelta[i] = scale * i;
    }

    for (int iy = 0; iy < HEIGHT; iy++) {
//
//         md_float x0 = centerX - scale * WIDTH / 2,
//                  y0 = centerY + (HEIGHT/2 - iy) * scale;

        pmd_float y0 = {0};
        pmd_float_set(y0, centerY + (HEIGHT/2 - iy) * scale);

        for (int ix = 0; ix < WIDTH; ix+= PACKED_SIZE) {
            pmd_float x0 = {0};
            pmd_float_set(x0, centerX - scale*WIDTH / 2 + ix * scale);
            pmd_float_add(x0, x0, initDelta);

            /*
                z' = z^2 + z_0 = (x+iy)^2 + x_0 + iy_0 = x^2 - y^2 + x_0 + i(2x*y + y_0)
                x' = x^2 - y^2 + x0
                y' = 2xy + y_0
            */
            pmd_float x; pmd_float_copy(x, x0);
            pmd_float y; pmd_float_copy(y, y0);

            int iter[PACKED_SIZE] = {0};
            for (int i = 0; i < MD_MAX_ITER; i++) {
                pmd_float x2 = {0}; pmd_float_mul(x2, x, x);
                pmd_float y2 = {0}; pmd_float_mul(y2, y, y);
                pmd_float xy_2; pmd_float_mul(xy_2, x, y); pmd_float_add(xy_2, xy_2, xy_2);
                // md_float x2 = x*x, y2 = y*y, xy_2 = 2*x*y;

                pmd_float r2; pmd_float_add(r2, x2, y2);
                pcmp cmp; pmd_float_cmp(cmp, r2, ESCAPE_RADIUS2);

                // if (x2 + y2 > ESCAPE_RADIUS2)
                    // break;
                uint64_t mask = (1 << PACKED_SIZE) - 1;
                for (int j = 0; j < PACKED_SIZE; j++) {
                    mask = mask >> (1- !!cmp[j]);
                    iter[j] += !!cmp[j];
                }
                if (!mask) break;

                pmd_float_copy(x, x2);
                pmd_float_sub(x, x, y2);
                pmd_float_add(x, x, x0);

                pmd_float_copy(y, xy_2);
                pmd_float_add(y, y, y0);
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
        int escN = md.escapeN[idx];

        if (escN == MD_MAX_ITER)
            md.screen[idx] = 0; // Black 
        else {
            uint8_t red   = MD_MAX_ITER - escN;
            uint8_t green = 95*(1+sin(sqrt(escN)/1.1));
            uint8_t blue  = 200 - 200*cosf(escN / 230);

            md.screen[idx] = generateColor(red, green, blue);
        }

    }

    return 0;
}
