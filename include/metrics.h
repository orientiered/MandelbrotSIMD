#ifndef METRICS_H
#define METRICS_H

//! Dependencies:
//! stdio.h
//! SFML/Gpaphics.hpp
//! mandelbrot.h
/*============================= STRUCTS ====================================================*/
typedef struct doublePair {
    double first;
    double second;
} doublePair_t;

typedef struct {
    unsigned testCount; ///< Number of tests performed
    sf::Time worst;     ///< Worst time in the test
    sf::Time best;      ///< Best  time in the test
    sf::Time average;   ///< Average time
    sf::Time error;     ///< Error of compiting average time (standard deviation of it)
} testTime_t;


/*============================== FUNCTIONS ===================================================*/
/*!    
    @brief Calculate standard deviation of value online
    Note: function is not thread-safe because it uses static variables
    @param getResult = 0 --> store value and use it calculations
                > 0 --> return average value and standard deviation in doublePair_t
                < 0 --> reset internal variables
    @return {average, standard deviation}
*/
doublePair_t runningSTD(double value, int getResult);


/*!
    @brief Test all mandelbrot functions and save result in file
    Test time for each function is at least duration and minimum of test_count tests are performed 
*/
int testMandelbrot(FILE *file, const mdContext_t md, const unsigned test_count, const sf::Time duration);


/*!
    @brief Test performance of given mandelbrot function
    Prints FPS, MSPF (ms per frame), best and worst computation time
    Function is tested at least test_count times and at least duration time
    @return Result of test in struct ( @see testTime_t )
*/
testTime_t testMandelbrotFunction(int (*mandelbrot)(const mdContext_t md),
                                  const mdContext_t md,         ///< Mandelbrot calc function and its context
                                  const unsigned test_count,    ///< Minimum number of tests to perform
                                  const sf::Time duration       ///< Minimum testing time
                                 );


/*!
    @brief Write result of test in nice manner to the file
    @param comment String to put on top of the results (additional info, such as used function or special conditions)
    @return 0 on success, 1 if error occured
*/
int saveMandelbrotTestResult(FILE *file, const testTime_t testResult, const char *comment);


/*!
    @brief Write in str information about current run info
    Included info: resolution, center coordinates, maximum number of iterations,
    width of rendered part of coordinate plane, type of fp number used in calculations,
    size of pack in calculateMandelbrotAutoVec,
    bitness of used SIMD instruction set (128, 256, 512) in calculateMandelbrotOptimized, number of packs of MM registers
    compiler and compile flags (they are provided with _COMPILER and _COMPILE_FLAGS defines made by compiler in metrics.cpp)
    @param str String to write info. Make sure it is big enough (512 bytes e.g.), because there's no checks for overflow
    @param md  Context (parameters) of mandelbrot set
    @return Number of written characters
*/
int getProgramAndRunInfo(char *str, const mdContext_t md);

#endif
