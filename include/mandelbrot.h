#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdint.h>

/*================================= TYPEDEFS ============================================*/

/// @brief Float type used for calculations
typedef float md_float;

/// @brief Uncomment type you have chosen in typedef and recompile to get suitable optimizations
#define MANDELBROT_FLOAT
// #define MANDELBROT_DOUBLE

/// @brief Context with essential info to calculate mandlebrot set
typedef struct {
    uint32_t *screen;           ///< Array of rgba pixels
    uint32_t *escapeN;          ///< Array with escape iterations for every pixel
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

const md_float MD_DEFAULT_PLANE_WIDTH = 3.5;

const md_float MD_ESCAPE_RADIUS = 10.0;
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
