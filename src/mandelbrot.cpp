#include <cstdint>
#include <mandelbrot.h>

#include <stdlib.h>
#include <math.h>
#include <stdio.h>


/// @brief Get 32-bit rgba color from r,g,b
static inline uint32_t generateColor(int r, int g, int b) {
    // SFML uses rgba
    return (r << 0) + (g << 8) + (b << 16) + (255 << 24);
}

static inline uint32_t colorFromIter(const uint32_t iter, const uint32_t maxIter) {
    if (iter == maxIter)
        return 0;

    const uint8_t red   = MD_DEFAULT_MAX_ITER - iter;
    const uint8_t green = 95*(1+sin(sqrt(iter)*(1/1.1)));
    const uint8_t blue  = 40. * logf(iter);

    return generateColor(red, green, blue);
}

int precalculateColors(const mdContext_t md) {
    for (int iter = 0; iter <= md.maxIter; iter++) {
        md.colorsPrecalc[iter] = colorFromIter(iter, md.maxIter); 
    }

    return 0;
}

mdContext_t mdContextCtor(int WIDTH, int HEIGHT) {
    const int ARRAY_ALIGNMENT = MD_ALIGN / sizeof(uint32_t);

    if (WIDTH < 0) {
        printf("Width can only be positive. Fixed it for you: %d -> %d\n", WIDTH, -WIDTH);
        WIDTH = -WIDTH;
    }

    if (WIDTH < 0) {
        printf("Height can only be positive. Fixed it for you: %d -> %d\n", HEIGHT, -HEIGHT);
        HEIGHT = -HEIGHT;
    }

    if ((WIDTH % AUTO_VEC_PACK_SIZE != 0) || WIDTH % ( MM_SIZE * MM_PACKS / sizeof(md_float) ) != 0) {
        printf("Not compatible width. Searching for nearest appropriate width: %d ->", WIDTH);

        while ((WIDTH % AUTO_VEC_PACK_SIZE != 0) || WIDTH % ( MM_SIZE * MM_PACKS / sizeof(md_float) ) != 0) {
            WIDTH++;
        }

        printf(" %d\n", WIDTH);
    }

    mdContext_t context =
    {   .screen  = (uint32_t *) calloc(WIDTH*HEIGHT, sizeof(uint32_t)),
        .UNALIGNED_escapeN = (uint32_t *) calloc(WIDTH*HEIGHT + ARRAY_ALIGNMENT, sizeof(uint32_t)),
        .WIDTH   = WIDTH,        .HEIGHT  = HEIGHT,
        .centerX = MD_DEFAULT_X, .centerY = MD_DEFAULT_Y,
        .scale   = MD_DEFAULT_PLANE_WIDTH / WIDTH,
        .maxIter = MD_DEFAULT_MAX_ITER,
        .colorsPrecalc = (uint32_t *) calloc(MD_ITERS_LIMIT, sizeof(uint32_t))
    };

    int addrShift = ((MD_ALIGN - (size_t)context.UNALIGNED_escapeN % MD_ALIGN) % MD_ALIGN) / sizeof(uint32_t);
    context.escapeN = context.UNALIGNED_escapeN + addrShift;

    precalculateColors(context);

    return context;
}

int mdContextDtor(mdContext_t *context) {
    free(context->screen);
    free(context->UNALIGNED_escapeN);
    free(context->colorsPrecalc);
    return 0;
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
            for (; iter < MD_DEFAULT_MAX_ITER; iter++) {
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
#define PACKED_SIZE MM_SIZE / 8 / sizeof(md_float)

#if MM_SIZE == 128
    typedef __m128i MMi_t;

    #define _MM_LOAD_SI(ptr) _mm_load_si128((const MMi_t *) ptr)
    #define _MM_STORE_SI(ptr, a) _mm_store_si128(ptr, a)
    #define _MM_AND_EPI(a, b) _mm_and_si128(a, b)
    #define _MM_TESTZ(a, b) _mm_testz_si128(a, b)

    #define _MM_SETZERO(a) _mm_xor_si128(a, a)

    #define _MM_SHUFFLE_i64_TO_i32(a) _mm_shuffle_epi32(a, 0b00100000)

    #if defined(MANDELBROT_FLOAT)
        typedef __m128  MM_t;

        #define _MM_LOAD(ptr)  _mm_load_ps(ptr)
        #define _MM_SET1(val) _mm_set_ps1(val)

        #define _MM_ADD_EPI(a, b) _mm_add_epi32(a, b)
        #define _MM_ADD(a, b) _mm_add_ps(a, b)

        #define _MM_SUB(a, b) _mm_sub_ps(a, b)
        #define _MM_MUL(a, b) _mm_mul_ps(a, b)

        #define _MM_CMPLE_TO_EPI(a, b) (MMi_t) _mm_cmple_ps(a, b)
    #else
        typedef __m128d  MM_t;

        #define _MM_LOAD(ptr)  _mm_load_pd(ptr)
        #define _MM_SET1(val) _mm_set_pd1(val)
        #define _MM_STORE_HALF(ptr, a) _mm_storeu_si64(ptr, a)

        #define _MM_ADD_EPI(a, b) _mm_add_epi64(a, b)
        #define _MM_ADD(a, b) _mm_add_pd(a, b)

        #define _MM_SUB(a, b) _mm_sub_pd(a, b)
        #define _MM_MUL(a, b) _mm_mul_pd(a, b)

        #define _MM_CMPLE_TO_EPI(a, b) (MMi_t) _mm_cmple_pd(a, b)

        #define _MM_CVTEPI64_EPI32_STORE(ptr, a) \
            _MM_STORE_HALF(ptr, _MM_SHUFFLE_i64_TO_i32(a))

    #endif

#elif MM_SIZE == 256
    typedef __m256i MMi_t;
    #define _MM_LOAD_SI(ptr) _mm256_load_si256((const MMi_t *) ptr)
    #define _MM_STORE_SI(ptr, a) _mm256_store_si256((MMi_t *)ptr, a)
    #define _MM_AND_EPI(a, b) _mm256_and_si256(a, b)
    #define _MM_TESTZ(a, b) _mm256_testz_si256(a, b)

    #define _MM_SETZERO(a) _mm256_xor_si256(a, a)


    #define _MM_SHUFFLE_i64_TO_i32(a) \
        _mm256_permutevar8x32_epi32(a, _mm256_setr_epi32(0,2,4,6,0,0,0,0))
    #if defined(MANDELBROT_FLOAT)
        typedef __m256  MM_t;
        #define _MM_LOAD(ptr)  _mm256_load_ps(ptr)

        #define _MM_SET1(val) _mm256_set1_ps(val)

        #define _MM_ADD(a, b) _mm256_add_ps(a, b)
        #define _MM_ADD_EPI(a, b) _mm256_add_epi32(a, b)
        #define _MM_SUB(a, b) _mm256_sub_ps(a, b)
        #define _MM_MUL(a, b) _mm256_mul_ps(a, b)

        #define _MM_CMPLE_TO_EPI(a, b) _mm256_castps_si256( _mm256_cmp_ps(a, b, _CMP_LE_OS))
    #else
        typedef __m256d  MM_t;
        #define _MM_LOAD(ptr)  _mm256_load_pd(ptr)

        #define _MM_SET1(val) _mm256_set1_pd(val)
        #define _MM_STORE_HALF(ptr, a) \
            _mm_store_si128( (__m128i *)ptr, _mm256_extracti128_si256(a, 0))

        #define _MM_ADD(a, b) _mm256_add_pd(a, b)
        #define _MM_ADD_EPI(a, b) _mm256_add_epi64(a, b)
        #define _MM_SUB(a, b) _mm256_sub_pd(a, b)
        #define _MM_MUL(a, b) _mm256_mul_pd(a, b)

        #define _MM_CMPLE_TO_EPI(a, b) (MMi_t) _mm256_cmp_pd(a, b, _CMP_LE_OS)

        #define _MM_CVTEPI64_EPI32_STORE(ptr, a) \
            _MM_STORE_HALF((__m128i *)ptr, _MM_SHUFFLE_i64_TO_i32(a))

    #endif

#elif MM_SIZE == 512
    typedef __m512i MMi_t;
    #define _MM_LOAD_SI(ptr) _mm512_load_si512((const MMi_t *) ptr)
    #define _MM_STORE_SI(ptr, a) _mm512_store_si512(ptr, a)
    #define _MM_AND_EPI(a, b) _mm512_and_si512(a, b)

    #define _MM_SETZERO(a) _mm512_xor_si512(a, a)

    #if defined(MANDELBROT_FLOAT)
        typedef __m512  MM_t;

        #define _MM_LOAD(ptr) _mm512_load_ps(ptr)

        #define _MM_SET1(val) _mm512_set1_ps(val)

        #define _MM_ADD(a, b) _mm512_add_ps(a, b)
        #define _MM_ADD_EPI(a, b) _mm512_add_epi32(a, b)

        #define _MM_SUB(a, b) _mm512_sub_ps(a, b)
        #define _MM_MUL(a, b) _mm512_mul_ps(a, b)

        #define _MM_CMPLE_MASK(a, b) _mm512_cmp_ps_mask(a, b, _CMP_LE_OS)
        // a[i] = a[i] + b[i] if mask[i]
        #define _MM_MASK_ADD_EPI(a, mask, b) \
            _mm512_mask_add_epi32(a, mask, a, b)
    #else
        typedef __m512d  MM_t;

        #define _MM_LOAD(ptr) _mm512_load_pd(ptr)

        #define _MM_SET1(val) _mm512_set1_pd(val)
        #define _MM_STORE_HALF(ptr, a) \
            _mm256_store_si256((MMi_t *) ptr, _mm512_extracti32x8_epi32(a, 0))

        #define _MM_ADD(a, b) _mm512_add_pd(a, b)
        #define _MM_ADD_EPI(a, b) _mm512_add_epi64(a, b)

        #define _MM_SUB(a, b) _mm512_sub_pd(a, b)
        #define _MM_MUL(a, b) _mm512_mul_pd(a, b)

        #define _MM_CMPLE_MASK(a, b) _mm512_cmp_pd_mask(a, b, _CMP_LE_OS)
        // a[i] = a[i] + b[i] if mask[i]
        #define _MM_MASK_ADD_EPI(a, mask, b) \
            _mm512_mask_add_epi64(a, mask, a, b)

        #define _MM_CVTEPI64_EPI32_STORE(ptr, a) \
            _mm256_store_si256((__m256i *)ptr, _mm512_cvtepi64_epi32(a))
    #endif

#else
    #error Supported MM_SIZE: 128, 256, 512
#endif


int calculateMandelbrotOptimized(const mdContext_t md) {

    /*Unpacking values from mdContext_t for convinience */
    uint32_t *escapeN = md.escapeN;
    const md_float centerX = md.centerX, centerY = md.centerY;
    const md_float scale = md.scale;
    const int WIDTH = md.WIDTH, HEIGHT = md.HEIGHT;
    const int maxIter = md.maxIter;
    /*Points never come back after ESCAPE_RADIUS*/
    const md_float ESCAPE_RADIUS2 = MD_ESCAPE_RADIUS * MD_ESCAPE_RADIUS;
    const MM_t escapeR2 = _MM_SET1(ESCAPE_RADIUS2);


    // 0, dx, 2*dx, ..., (PACKED_SIZE-1) * dx
    alignas(64) md_float initDelta__[PACKED_SIZE];
    for (int i = 0; i < PACKED_SIZE; i++) {
        initDelta__[i] = scale * i;
    }
    const MM_t initDelta = _MM_LOAD(initDelta__);

    // Mask with low bit in every float
    alignas(64) uint8_t logicMask__[MM_SIZE / 8] = {0};
    for (uint8_t i = 0; i < PACKED_SIZE; i++) {
        logicMask__[i*sizeof(md_float)] = 1;
    }
    const MMi_t logicMask = _MM_LOAD_SI(logicMask__);


    for (int iy = 0; iy < HEIGHT; iy++) {
        // Setting y0: the same for all x
        // y0 = centerY + (HEIGHT / 2 - iy) * scale
        MM_t y0[MM_PACKS];
        for (int i = 0; i < MM_PACKS; i++)
            y0[i] = _MM_SET1(centerY + (HEIGHT / 2 - iy) * scale);

        for (int ix = 0; ix < WIDTH; ix+= PACKED_SIZE*MM_PACKS) {
            // x0[k] = centerX - scale*WIDTH / 2 + ix * scale + initDelta[k]
            MM_t x0[MM_PACKS];
            for (int i = 0; i < MM_PACKS; i++)
                x0[i] = _MM_ADD(_MM_SET1(centerX - scale*WIDTH / 2 + (ix + PACKED_SIZE * i) * scale), initDelta);
            // x0 = _MM_ADD(x0, initDelta);

            /*
                Mandelbrot formula:
                x' = x^2 - y^2 + x0
                y' = 2xy + y_0
            */
            MM_t x[MM_PACKS];
            for (int i = 0; i < MM_PACKS; i++)
                x[i] = x0[i];
            MM_t y[MM_PACKS];
            for (int i = 0; i < MM_PACKS; i++)
                y[i] = y0[i];

            MMi_t escapeIter[MM_PACKS];
            for (int i = 0; i < MM_PACKS; i++)
                escapeIter[i] = _MM_SETZERO(escapeIter[i]);

            for (int iteration = 0; iteration < maxIter; iteration++) {
                /* md_float x2 = x*x, y2 = y*y, xy_2 = 2*x*y; */
                MM_t x2[MM_PACKS];
                MM_t y2[MM_PACKS];   
                for (int i = 0; i < MM_PACKS; i++)
                    x2[i] = _MM_MUL(x[i], x[i]);
                for (int i = 0; i < MM_PACKS; i++)
                    y2[i] = _MM_MUL(y[i], y[i]);
                

                MM_t r2[MM_PACKS];
                for (int i = 0; i < MM_PACKS; i++)
                    r2[i] = _MM_ADD(x2[i], y2[i]);


                // This section vastly differs in AVX512 and SSE/AVX2
            #if MM_SIZE == 512
                // Comparing r^2 <= ESCAPE_RADIUS^2
                // cmpMask[i] (bits) = (r2[i] <= escapeR2 )
                uint16_t cmpMask[MM_PACKS];
                for (int i = 0; i < MM_PACKS; i++)
                    cmpMask[i] = _MM_CMPLE_MASK(r2[i], escapeR2);
                // If cmpMask == 0 => all points escaped => break
                bool notAllEscaped = false;
                for (int i = 0; i < MM_PACKS; i++)
                    notAllEscaped |= cmpMask[i];
                if (!notAllEscaped) break;

                // iter++ for points that have not escaped yet
                // escapeIter[i]++ for i in cmpMask
                for (int i = 0; i < MM_PACKS; i++)
                    escapeIter[i] = _MM_MASK_ADD_EPI(escapeIter[i], cmpMask[i], logicMask);
            #else
                // Comparing r^2 <= ESCAPE_RADIUS^2
                // cmp = 0xFFFFFFF for true and 0x0 for false
                MMi_t cmp[MM_PACKS];
                for (int i = 0; i < MM_PACKS; i++)
                    cmp[i] = _MM_CMPLE_TO_EPI(r2[i], escapeR2);
                // If cmp == 0 => all points escaped => break
                bool allEscaped = true;
                for (int i = 0; i < MM_PACKS; i++)
                    allEscaped &= _MM_TESTZ(cmp[i], cmp[i]) ;

                if (allEscaped) break;

                // Converting mask to integer 1 or 0
                // logicMask = low bit for every float in MM_t
                for (int i = 0; i < MM_PACKS; i++)
                    cmp[i] = _MM_AND_EPI(cmp[i], logicMask);
                // iter++ for points that have not escaped yet
                for (int i = 0; i < MM_PACKS; i++)
                    escapeIter[i] = _MM_ADD_EPI(escapeIter[i], cmp[i]);
            #endif
                MM_t xy_2[MM_PACKS];
                for (int i = 0; i < MM_PACKS; i++)
                    xy_2[i] = _MM_MUL(x[i], y[i]);
                for (int i = 0; i < MM_PACKS; i++)
                    xy_2[i] = _MM_ADD(xy_2[i], xy_2[i]);

                // x = x2 - y2 + x0;
                for (int i = 0; i < MM_PACKS; i++)
                    x[i] = _MM_ADD(_MM_SUB(x2[i],y2[i]), x0[i]);

                // y = xy_2    + y0;
                for (int i = 0; i < MM_PACKS; i++)
                    y[i] = _MM_ADD(xy_2[i], y0[i]);

            }


        // Writing number of iterations to the memory
        // !Alignment is controlled by MD_ALIGN. By default 64 bytes for any store instruction
        // ! ix += PACKED_SIZE doesn't break align
        #ifdef MANDELBROT_DOUBLE
            for (int i = 0; i < MM_PACKS; i++)
                _MM_CVTEPI64_EPI32_STORE(&escapeN[iy*WIDTH +ix + PACKED_SIZE*i], escapeIter[i]);
        #else
            for (int i = 0; i < MM_PACKS; i++)
                _MM_STORE_SI((MMi_t *)&escapeN[iy*WIDTH +ix + PACKED_SIZE*i], escapeIter[i]);
        #endif
        }
    }


    return 0;

}

int calculateMandelbrotAutoVec(const mdContext_t md) {
    /*Unpacking values from mdContext_t for convinience */
    uint32_t *escapeN = md.escapeN;
    const md_float centerX = md.centerX, centerY = md.centerY;
    const md_float scale = md.scale;
    const int WIDTH = md.WIDTH, HEIGHT = md.HEIGHT;
    const int maxIter = md.maxIter;
    /*Points never come back after ESCAPE_RADIUS*/
    const md_float ESCAPE_RADIUS2 = MD_ESCAPE_RADIUS * MD_ESCAPE_RADIUS;

    md_float initDelta[AUTO_VEC_PACK_SIZE] = {};
    for (int i = 0; i < AUTO_VEC_PACK_SIZE; i++)
        initDelta[i] = scale*i;

    for (int iy = 0; iy < HEIGHT; iy++) {
        const md_float y0_single = centerY + (HEIGHT / 2 - iy) * scale;

        md_float y0[AUTO_VEC_PACK_SIZE] = {};
        for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
            y0[index] = y0_single;

        for (int ix = 0; ix < WIDTH; ix += AUTO_VEC_PACK_SIZE) {
            const md_float x0_start = centerX - scale*WIDTH / 2 + ix*scale;

            md_float x0[AUTO_VEC_PACK_SIZE] = {};
            for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                x0[index] = x0_start + initDelta[index];

            md_float x[AUTO_VEC_PACK_SIZE] = {};
            for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                x[index] = x0[index];

            md_float y[AUTO_VEC_PACK_SIZE] = {};
            for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                y[index] = y0[index];

            uint32_t escapeIter[AUTO_VEC_PACK_SIZE] = {0};

            for (int iteration = 0; iteration < maxIter; iteration++) {
                md_float x2[AUTO_VEC_PACK_SIZE] = {};
                for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                    x2[index] =  x[index] * x[index];

                md_float y2[AUTO_VEC_PACK_SIZE] = {};
                for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                    y2[index] =  y[index] * y[index];

                md_float r2[AUTO_VEC_PACK_SIZE] = {};
                for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                    r2[index] = x2[index] + y2[index];

                uint32_t cmpMask[AUTO_VEC_PACK_SIZE] = {};
                for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                    cmpMask[index] = (r2[index] <= ESCAPE_RADIUS2);

                int notEscaped = 0;
                for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                    notEscaped |= cmpMask[index];

                if (notEscaped == 0) break;

                for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                    escapeIter[index] = escapeIter[index] + cmpMask[index];

                md_float xy[AUTO_VEC_PACK_SIZE] = {};
                for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                    xy[index] = x[index] * y[index];

                // x = x^2 - y^2 + x0;
                for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                    x[index] = x2[index] - y2[index] + x0[index];
                // y = 2xy       + y0
                for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                    y[index] = xy[index] + xy[index] + y0[index];
            }

            const int writeOffset = iy*WIDTH + ix;
            for (int index = 0; index < AUTO_VEC_PACK_SIZE; index++)
                escapeN[writeOffset + index] = escapeIter[index];
        }
    }

    return 0;
}

int convertItersToColor(const mdContext_t md) {
    // Idea: calculate exact colors for 256 iters and interpolate between others

    for (int idx = 0; idx < md.WIDTH * md.HEIGHT; idx++) {
        int iter = md.escapeN[idx];

        md.screen[idx] = md.colorsPrecalc[iter];

    }

    return 0;
}
