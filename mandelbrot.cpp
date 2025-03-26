#include <mandelbrot.h>

#include <stdlib.h>

mdContext_t mdContextCtor(int WIDTH, int HEIGHT) {
    mdContext_t context = { .screen = (uint32_t *) calloc(WIDTH*HEIGHT, sizeof(uint32_t)),
                            .WIDTH   = WIDTH,        .HEIGHT  = HEIGHT,
                            .centerX = MD_DEFAULT_X, .centerY = MD_DEFAULT_Y,
                            .scale = MD_DEFAULT_PLANE_WIDTH / WIDTH};

    return context;
}

int mdContextDtor(mdContext_t *context) {
    free(context->screen);
    return 0;
}

/// @brief Get 32-bit rgba color from r,g,b
inline uint32_t generateColor(int r, int g, int b) {
    // bytes are reversed
    return (r << 0) + (g << 8) + (b << 16) + (255 << 24);
}

int calculateMandelbrot(uint32_t *pixels,
                        const md_float centerX, const md_float centerY,
                        const md_float scale,
                        const int WIDTH, const int HEIGHT) {

    const md_float ESCAPE_RADIUS2 = 100.0;

    for (int iy = 0; iy < HEIGHT; iy++) {
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
                md_float x2 = x*x, y2 = y*y, xy_2 = 2*x*y;

                if (x2 + y2 > ESCAPE_RADIUS2)
                    break;

                x = x2 - y2 + x0;
                y = xy_2    + y0;
            }

            pixels[iy*WIDTH+ix] = (iter == MD_MAX_ITER) ?
                                    0 : // black
                                    generateColor(MD_MAX_ITER-iter, iter/2*3, iter%5*64);
        }
    }
    return 0;
}

const int PACKED_SIZE = 256/8 / sizeof(md_float);

typedef md_float pmd_float[PACKED_SIZE];
typedef int   pcmp[PACKED_SIZE]; // packed cmp array

inline void pmd_float_add(md_float *res, const pmd_float a, const pmd_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) {
        res[i] = a[i] + b[i];
    }
}

inline void pmd_float_sub(md_float *res, const pmd_float a, const pmd_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) {
        res[i] = a[i] - b[i];
    }
}

inline void pmd_float_mul(md_float *res, const pmd_float a, const pmd_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) {
        res[i] = a[i] * b[i];
    }
}

inline void pmd_float_cmp(int *cmp, const pmd_float a, const md_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) {
        cmp[i] = a[i] < b;
    }
}

inline void pmd_float_set(md_float *a, const md_float v) {
    for (int i = 0; i < PACKED_SIZE; i++) {
        a[i] = v;
    }
}

inline void pmd_float_copy(md_float *a, const pmd_float b) {
    for (int i = 0; i < PACKED_SIZE; i++) {
        a[i] = b[i];
    }
}

int calculateMandelbrotOptimized(uint32_t *pixels,
                        const md_float centerX, const md_float centerY,
                        const md_float scale,
                        const int WIDTH, const int HEIGHT) {


    const md_float ESCAPE_RADIUS2 = 100.0;

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
                pixels[iy*WIDTH+ix + i] = (iter[i] == MD_MAX_ITER) ?
                                0 : // black
                                // generateColor(MD_MAX_ITER-iter[i], iter[i]/2*3, iter[i]%5*64);
                                generateColor(MD_MAX_ITER-iter[i], 0, 0);

            }
        }
    }


    return 0;

}
