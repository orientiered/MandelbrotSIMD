#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdint.h>
#include <thread>
#include <mutex>

#ifndef NDEBUG
    #define DBG(...) __VA_ARGS__
#else
    #define DBG(...)  
#endif

/*================================= IMPORTANT CONSTANTS ============================================*/

/// @brief Uncomment type you want to use
// #define MANDELBROT_FLOAT
#define MANDELBROT_DOUBLE

/// @brief Number of packs of md_float that are processed in one iteration
/// Improves conveyorization by reducing data dependency
#define MM_PACKS 6

//! CRUCIAL PARAMETER
//! Size of vector register in bits
#define MM_SIZE 256    // size of current mm register
//! xmm -- 128 (SSE4.2)
//! ymm -- 256 (AVX2)
//! zmm -- 512 (AVX512)
//! Intrinsics and types will be chosen based on that define

/// @brief Number of md_floats that will be processed simultaneously
/// @brief Used only in version that is vectorized automatically
#define AUTO_VEC_PACK_SIZE 32

/// @brief Number of threads for rendering
const int THREAD_POOL_SIZE = 8;

/*============================== FLOAT TYPE =============================================*/

/// @brief Float type used for calculations
#if defined(MANDELBROT_FLOAT)
    typedef float md_float;
    const char * const MD_FLOAT_TYPE_STR = "float";
#elif defined(MANDELBROT_DOUBLE)
    typedef double md_float;
    const char * const MD_FLOAT_TYPE_STR = "double";

#else
    #error Type error: use only MANDELBROAT_FLOAT or MANDELBROAT_DOUBLE
#endif

/*================================ CONSTANTS ============================================*/

/// @brief Maximum number of iterations per pixel (default value)
const int MD_DEFAULT_MAX_ITER = 256;

/// @brief Global maximum for maxIter
const int MD_ITERS_LIMIT = 4096;

/// @brief Default center position
const md_float MD_DEFAULT_X = -0.5;
const md_float MD_DEFAULT_Y =  0.0;

/// @brief Starting length on x axis
const md_float MD_DEFAULT_PLANE_WIDTH = 3.5;

const md_float MD_ESCAPE_RADIUS = 10.0;

/*================================= STRUCTS ============================================*/

enum mdThreadStatus {
    MD_THREAD_STOPPED = -1, ///< Thread stopped it's execution
    MD_THREAD_WAITING =  0, ///< Thread completed it's work and waiting
    MD_THREAD_WORKING =  1  ///< Thread calculates pixels
};

typedef struct threadPool_t {
    std::thread thrdPool[THREAD_POOL_SIZE];             ///< Array with threads
    std::mutex mtx;                                     ///< Mutex for safe currentAvailableLine reading and writing
    enum mdThreadStatus thrdStatus[THREAD_POOL_SIZE];   ///< Array with status of each thread

    int currentAvailableLine;                           ///< Number of first line available for rendering
    /*
    currentAvailableLine < 0              --> threadPool is not initialized (signal for threads to stop)
    currentAvailableLine in [0; md.WIDTH) --> rendering
    currentAvailableLine >= md.WIDTH      --> waiting for next frame 
    */
} threadPool_t;

/// @brief Context with essential info to calculate mandlebrot set
typedef struct {
    uint32_t *screen;           ///< Array of rgba pixels
    uint32_t *escapeN;          ///< Array with escape iterations for every pixel
    int WIDTH, HEIGHT;          ///< Width and height of the screen
    md_float centerX, centerY;  ///< Coordinates of center position on complex plane
    md_float scale;             ///< Scale = (unit length) / (pixels per unit length)
    int maxIter;                ///< Maximum number of iterations per dot
    uint32_t *colorsPrecalc;    ///< Precalculated colors for each iteration

    threadPool_t *thrdPool;     ///< Pointer to struct with threads that will compute mandelbrot set
} mdContext_t;



/*================================ FUNCTIONS ============================================*/

/// @brief Create mandelbrot context
/// Be careful, this function does not check calloc errors
mdContext_t mdContextCtor(int WIDTH, int HEIGHT);

/// @brief Destroy mandelbrot context and free resources
int mdContextDtor(mdContext_t *context);

/// @brief Reconstruct mandelbrot context with new width and height
int mdContextResize(mdContext_t *md, int WIDTH, int HEIGHT);


int mdThreadPoolCtor(threadPool_t *pool, mdContext_t *md);

int mdThreadPoolDtor(threadPool_t *pool);

/// @brief Calculate color for each iteration from 0 to md.maxIter and store them in md.colorsPrecals
/// Run this function when maxIter changes
int precalculateColors(const mdContext_t md);

/// @brief Calculate escape iteration for each pixel
int calculateMandelbrot(const mdContext_t md);

/// @brief Calculate escape iteration for each pixel with intrinsics optimization
int calculateMandelbrotOptimized(const mdContext_t md);

/// @brief Run intrinsic optimized version on multiple threads
// Requieres initialization of thrdPool field
int calculateMandelbrotThreaded(const mdContext_t md);


/// @brief Calculate escape iteration for each pixel with hope that GCC vectorized code
int calculateMandelbrotAutoVec(const mdContext_t md);


/// @brief Convert iters from md.escapeN to pixels in md.screen
int convertItersToColor(const mdContext_t md);


#endif
