#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdint.h>

/*================================= TYPEDEFS ============================================*/

/// @brief Uncomment type you have chosen in typedef and recompile to get suitable optimizations
#define MANDELBROT_FLOAT
// #define MANDELBROT_DOUBLE

/// @brief Float type used for calculations
#if defined(MANDELBROT_FLOAT)
    typedef float md_float;
#elif defined(MANDELBROT_DOUBLE)
    typedef double md_float;
#else
    #error Type error: use only MANDELBROAT_FLOAT or MANDELBROAT_DOUBLE
#endif

//! CRUCIAL PARAMETER
//! Size of vector register in bits
//! xmm -- 128 (SSE4.2)
//! ymm -- 256 (AVX2)
//! zmm -- 512 (AVX512)
//! Intrinsics and types will be chosen based on that define
#define MM_SIZE 512    // size of current mm register

/// @brief Context with essential info to calculate mandlebrot set
typedef struct {
    uint32_t *screen;           ///< Array of rgba pixels
    uint32_t *UNALIGNED_escapeN; ///< Array with escape iterations for every pixel
    uint32_t *escapeN;          ///< Aligned by MD_ALIGN bytes version of UNALIGNED_escapeN
    int WIDTH, HEIGHT;          ///< Width and height of the screen
    md_float centerX, centerY;  ///< Coordinates of center position on complex plane
    md_float scale;             ///< Scale = (unit length) / (pixels per unit length)
} mdContext_t;

/*================================ CONSTANTS ============================================*/

/// @brief Maximum number of iterations per pixel
const int MD_MAX_ITER = 256;

/// @brief Default center position
const md_float MD_DEFAULT_X = -0.5;
const md_float MD_DEFAULT_Y =  0.0;

/// @brief Starting length on x axis
const md_float MD_DEFAULT_PLANE_WIDTH = 3.5;

const md_float MD_ESCAPE_RADIUS = 10.0;

/// @brief Alignment in bytes to ensure correct store instruction
const int MD_ALIGN = 64;

/*================================ FUNCTIONS ============================================*/

/// @brief Create mandelbrot context
/// Be careful, this function does not check calloc errors and expects WIDTH and HEIGHT to be positive
mdContext_t mdContextCtor(int WIDTH, int HEIGHT);

/// @brief Destroy mandelbrot context and free resources
int mdContextDtor(mdContext_t *context);

/// @brief Calculate escape iteration for each pixel
int calculateMandelbrot(const mdContext_t md);

/// @brief Calculate escape iteration for each pixel with optimization
int calculateMandelbrotOptimized(const mdContext_t md);

/// @brief Convert iters from md.escapeN to pixels in md.screen
int convertItersToColor(const mdContext_t md);


#endif
