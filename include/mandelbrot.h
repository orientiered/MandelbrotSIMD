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
/*================================ FUNCTIONS ============================================*/

/// @brief Create mandelbrot context
/// Be careful, this function does not check calloc errors and expects WIDTH and HEIGHT to be positive
mdContext_t mdContextCtor(int WIDTH, int HEIGHT);

/// @brief Destroy mandelbrot context and free resources
int mdContextDtor(mdContext_t *context);

/// @brief Calculate colors for each pixel
int calculateMandelbrot(uint32_t *pixels,
                        const md_float centerX, const md_float centerY,
                        const md_float scale,  // length per pixel
                        const int WIDTH, const int HEIGHT);

int calculateMandelbrotOptimized(uint32_t *pixels,
                        const md_float centerX, const md_float centerY,
                        const md_float scale,
                        const int WIDTH, const int HEIGHT);

/// @brief Unpack context values to use in calculateMandelbrot function
/// Usage example:
/// calculateMandelbrot(mdContextUnpack(mandlebrot_context));
#define mdContextUnpack(context) context.screen, context.centerX, context.centerY, context.scale, context.WIDTH, context.HEIGHT

#endif
