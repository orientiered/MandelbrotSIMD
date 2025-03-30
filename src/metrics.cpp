#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <mandelbrot.h>
#include <metrics.h>

doublePair_t runningSTD(double value, int getResult) {
    //function to calculate standard deviation of some value
    //constructed to make calculations online, so static variables
    static doublePair_t result = {};
    static unsigned measureCnt = 0;     //number of values
    static double totalValue = 0;       //sum of value
    static double totalSqrValue = 0;    //sum of value^2
    // getResult > 1 --> calculate meanValue and std and return it
    // getResult = 0 --> store current value
    // getResult < 0 --> reset stored values
    if (getResult > 0) {
        if (measureCnt > 1) {
            result.first = totalValue / measureCnt;
            //printf("%g %g %u\n", totalSqrValue, totalValue, measureCnt);
            result.second = sqrt(totalSqrValue / measureCnt - result.first*result.first) / sqrt(measureCnt - 1);
        }
        return result;
    } else if (getResult == 0) {
        measureCnt++;
        totalValue += value;
        totalSqrValue += value*value;
    } else {
        measureCnt = 0;
        totalValue = totalSqrValue = 0;
    }
    return result;
}

testTime_t testMandelbrotFunction(int (*mandelbrot)(const mdContext_t md), const mdContext_t md,    ///< Mandelbrot calc function and its context
                                  const unsigned test_count,     ///< Number of test to preform. Leave 0 to use time limit instead
                                  const sf::Time durationLimit)  ///< Time limit for testing. Active only if test_count == 0
{

    sf::Clock clock;
    sf::Clock testDuration;

    runningSTD(0, -1); // reseting standard deviation calc function

    sf::Time worstCalcTime = sf::seconds(0),
             bestCalcTime  = sf::seconds(100);

    unsigned totalRendered = 0;
    while (true) {
        /**********************/
        clock.restart();
        mandelbrot(md);  //running given implementation
        sf::Time calcTime = clock.getElapsedTime();
        /**********************/

        runningSTD( (double) calcTime.asMicroseconds(), 0); // storing time
        // Updating best and worst times
        if (calcTime < bestCalcTime)
            bestCalcTime = calcTime;
        if (worstCalcTime < calcTime)
            worstCalcTime = calcTime;

        totalRendered++;
        // stopping testing
        if ((test_count > 0 && totalRendered >= test_count) ||
            (test_count == 0 && testDuration.getElapsedTime() > durationLimit) )
            break;
    }

    const doublePair_t meanTimeMicros = runningSTD(0, 1); // getting mean time and error (in microseconds)

    const testTime_t result = {.testCount = totalRendered,
                               .worst     = worstCalcTime, .best = bestCalcTime,
                               .average   = sf::microseconds((int64_t) meanTimeMicros.first),
                               .error     = sf::microseconds((int64_t) meanTimeMicros.second) };

    printf("Rendered %u frames within %f sec\n", totalRendered, testDuration.getElapsedTime().asSeconds());
    printf("FPS = %.2f, MSPF = %.3f +- %.3f\n", 1.0 / result.average.asSeconds(),
                                        (float)result.average.asMicroseconds() / 1000,
                                        (float)result.error.asMicroseconds() / 1000);
    printf("Best: %.2f, worst: %.2f\n", (float)result.best.asMicroseconds() / 1000,
                                        (float)result.worst.asMicroseconds() / 1000);

    return result;

}

int saveMandelbrotTestResult(FILE *file, const testTime_t testResult, const char *comment) {
    if (!file) {
        fprintf(stderr, "%s: no file specified\n", __FUNCTION__);
        return 1;
    }

    if (!comment) {
        fprintf(stderr, "%s: no comment string\n", __FUNCTION__);
        return 1;
    }

    fprintf(file, "\n\n");
    fprintf(file, "## %s\n", comment);

    fprintf(file, " + Number of tests: %u\n", testResult.testCount);

    const float MS_PER_MCS = 1000;

    float bestTimeMs  = (float) testResult.best.asMicroseconds() / MS_PER_MCS,
          worstTimeMs = (float) testResult.worst.asMicroseconds() / MS_PER_MCS,
          averageMs   = (float) testResult.average.asMicroseconds() / MS_PER_MCS,
          errorMs     = (float) testResult.error.asMicroseconds() / MS_PER_MCS,
          fps         = 1.0f / testResult.average.asSeconds();

    fprintf(file,   " + FPS: %.2f\n"
                    " + Milliseconds per frame: $%.3f \\pm %.3f$\n"
                    " + Best  time: %.2f\n"
                    " + Worst time: %.2f\n",
                    fps, averageMs, errorMs, bestTimeMs, worstTimeMs);

    return 0;
}


#ifndef _COMPILE_FLAGS
#define _COMPILE_FLAGS "Unknown"
#endif
#ifndef _COMPILER
#define _COMPILER "Unknown"
#endif

int getProgramAndRunInfo(char *str, const mdContext_t md) {
    size_t flagsLen = strlen(_COMPILE_FLAGS);
    const char *compileFlags = (flagsLen < 256) ? _COMPILE_FLAGS : "Parameter list is too long";
    return sprintf(str, "RESOLUTION: %dx%d\n"
                        "MAX_ITERS: %d\n"
                        "PLANE_WIDTH: %.5f\n"
                        "CENTER: %.3f, %.3f\n"
                        "MM_SIZE: %d\n"
                        "Auto vectorization size: %d\n"
                        "FLOAT TYPE: %s\n"
                        "COMPILER: %s\n"
                        "COMPILE FLAGS: %s\n",
                        md.WIDTH, md.HEIGHT,
                        MD_MAX_ITER,
                        MD_DEFAULT_PLANE_WIDTH,
                        md.centerX, md.centerY,
                        MM_SIZE,
                        AUTO_VEC_PACK_SIZE,
                        MD_FLOAT_TYPE_STR,
                        _COMPILER, compileFlags);
}
