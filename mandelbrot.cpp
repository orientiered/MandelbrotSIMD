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
    return (r << 24) + (g << 16) + (b << 8) + (255);
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
