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

/*=============================== PREPROCESSOR MAGIC ===========================================*/
/*=============================== ONE INTERFACE FOR SSE, AVX2 and AVX512 =======================*/
#include <immintrin.h>
// TODO: add support for double 
#define MM_SIZE 512    // size of current mm register
#define PACKED_SIZE MM_SIZE / 8 / sizeof(md_float)

#if MM_SIZE == 128
    typedef __m128 MM_t; 
    
    #define _MM_LOAD(ptr) _mm_load_ps(ptr)

    #define _MM_SET1(val) _mm_set_ps1(val)

    #define _MM_ADD(a, b) _mm_add_ps(a, b)
    #define _MM_SUB(a, b) _mm_sub_ps(a, b)
    #define _MM_MUL(a, b) _mm_mul_ps(a, b)
    #define _MM_CMPLE_MOVEMASK(a, b) _mm_movemask_ps( _mm_cmple_ps(a,b) )   // compare a <= b and create mask


#elif MM_SIZE == 256
    typedef __m256 MM_t;

    #define _MM_LOAD(ptr) _mm256_load_ps(ptr)

    #define _MM_SET1(val) _mm256_set1_ps(val)

    #define _MM_ADD(a, b) _mm256_add_ps(a, b)
    #define _MM_SUB(a, b) _mm256_sub_ps(a, b)
    #define _MM_MUL(a, b) _mm256_mul_ps(a, b)

    #define _MM_CMPLE_MOVEMASK(a, b) _mm256_movemask_ps( _mm256_cmp_ps(a,b, _CMP_LE_OS) )

#elif MM_SIZE == 512
    typedef __m512 MM_t;

    #define _MM_LOAD(ptr) _mm512_load_ps(ptr)

    #define _MM_SET1(val) _mm512_set1_ps(val)

    #define _MM_ADD(a, b) _mm512_add_ps(a, b)
    #define _MM_SUB(a, b) _mm512_sub_ps(a, b)
    #define _MM_MUL(a, b) _mm512_mul_ps(a, b)

    #define _MM_CMPLE_MOVEMASK(a, b) _mm512_cmp_ps_mask(a,b, _CMP_LE_OS)


#endif

typedef md_float pmd_float[PACKED_SIZE];


int calculateMandelbrotOptimized(const mdContext_t md) {

    /*Unpacking values from mdContext_t for convinience */
    uint32_t *escapeN = md.escapeN; 
    const md_float centerX = md.centerX, centerY = md.centerY;
    const md_float scale = md.scale;
    const int WIDTH = md.WIDTH, HEIGHT = md.HEIGHT;

    /*Points never come back after ESCAPE_RADIUS*/
    const md_float ESCAPE_RADIUS2 = MD_ESCAPE_RADIUS * MD_ESCAPE_RADIUS;
    const MM_t escapeR2 = _MM_SET1(ESCAPE_RADIUS2);


    const md_float dx = scale;
    alignas(64) pmd_float initDelta__;
    for (int i = 0; i < PACKED_SIZE; i++) {
        initDelta__[i] = scale * i;
    }
    const MM_t initDelta = _MM_LOAD(initDelta__);

    for (int iy = 0; iy < HEIGHT; iy++) {
//
//         md_float x0 = centerX - scale * WIDTH / 2,
//                  y0 = centerY + (HEIGHT/2 - iy) * scale;

        MM_t y0 = _MM_SET1(centerY + (HEIGHT / 2 - iy) * scale);
        // pmd_float_set(y0, centerY + (HEIGHT/2 - iy) * scale);
        for (int ix = 0; ix < WIDTH; ix+= PACKED_SIZE) {
            MM_t x0 = _MM_SET1(centerX - scale*WIDTH / 2 + ix * scale);
            x0 = _MM_ADD(x0, initDelta);

            /*
                z' = z^2 + z_0 = (x+iy)^2 + x_0 + iy_0 = x^2 - y^2 + x_0 + i(2x*y + y_0)
                x' = x^2 - y^2 + x0
                y' = 2xy + y_0
            */
            MM_t x = x0;
            MM_t y = y0;

            // int iter[PACKED_SIZE] = {0};
            int iter[PACKED_SIZE] = {0};

            for (int i = 0; i < MD_MAX_ITER; i++) {
                /* md_float x2 = x*x, y2 = y*y, xy_2 = 2*x*y; */
                MM_t x2   = _MM_MUL(x, x);
                MM_t y2   = _MM_MUL(y, y);
                MM_t xy_2 = _MM_MUL(x, y);
                xy_2 = _MM_ADD(xy_2, xy_2);

                MM_t r2 = _MM_ADD(x2, y2);
                
                // Filling xmm with ESCAPE_RADIUS^2
                // Comparing r^2 <= ESCAPE_RADIUS^2
                // cmp = 0xFFFFFFF for true and 0x0 for false 
                // mask_i = high bit of i-ый float in cmp
                int mask = _MM_CMPLE_MOVEMASK(r2, escapeR2);

                if (!mask) break;
                // if mask = 0 => all points escaped

                for (int j = 0; j < PACKED_SIZE; j++) {
                    iter[j] += mask & 1;    // incrementing iter if dot has not escaped yet
                    mask >>= 1;             // prepairing next bit
                }

                // x = x2 - y2 + x0;
                x = _MM_SUB(x2,y2);
                x = _MM_ADD(x, x0);

                // y = xy_2    + y0;
                y = _MM_ADD(xy_2, y0);
            }

            // Writing number of iterations to the memory
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
