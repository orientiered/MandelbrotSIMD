#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <stdio.h>
#include <string.h>

#include <mandelbrot.h>
#include <window.h>
#include <utils.h>

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

typedef struct {
    sf::Time worst;
    sf::Time best;
    sf::Time mean;
    sf::Time error;
} testTime_t;

testTime_t testMandelbrotFunction(int (*mandelbrot)(const mdContext_t md), const mdContext_t md, const unsigned test_count);

testTime_t testMandelbrotFunction(int (*mandelbrot)(const mdContext_t md), const mdContext_t md, const unsigned test_count) {
    sf::Clock clock;
    runningSTD(0, -1); // reseting

    sf::Time worstCalcTime = sf::seconds(0),
             bestCalcTime  = sf::seconds(100);

    for (unsigned total_rendered = 0; total_rendered < test_count; total_rendered++) {
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
    }

    const doublePair_t meanTimeMicros = runningSTD(0, 1); // getting mean time and error (in microseconds)

    const testTime_t result = {.worst = worstCalcTime, .best = bestCalcTime,
                               .mean  = sf::microseconds((int64_t) meanTimeMicros.first),
                               .error = sf::microseconds((int64_t) meanTimeMicros.second) };

    printf("FPS = %.2f, MSPF = %.3f +- %.3f\n", 1.0 / result.mean.asSeconds(),
                                        (float)result.mean.asMicroseconds() / 1000,
                                        (float)result.error.asMicroseconds() / 1000);
    printf("Best: %.2f, worst: %.2f\n", (float)result.best.asMicroseconds() / 1000,
                                        (float)result.worst.asMicroseconds() / 1000);

    return result;

}

int testMandelbrot(const mdContext_t md, const unsigned test_count) {

    printf("Running unoptimized version...\n");
    testTime_t noOptTime = testMandelbrotFunction(calculateMandelbrot, md, test_count);

    printf("\nRunning optimized version...\n");
    testTime_t optTime   = testMandelbrotFunction(calculateMandelbrotOptimized, md, test_count);

    printf("\nRunning autoVec version...\n");
    testTime_t autoVecTime   = testMandelbrotFunction(calculateMandelbrotAutoVec, md, test_count);

    return 0;
}

int main(int argc, const char *argv[]) {

    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    mdContext_t md = mdContextCtor(WIDTH, HEIGHT);

    char infoString[512] = "";
    getProgramAndRunInfo(infoString, md);
    printf("%s\n", infoString);

    bool test_mode = argc > 1;
    unsigned test_count = 0;
    if (test_mode) sscanf(argv[1], "%u", &test_count);

    uint32_t total_rendered = 0;

    sf::Clock clock;

    if (test_mode) {
        testMandelbrot(md, test_count);
        mdContextDtor(&md);
        return 0;
    }

    windowContext_t context;
    windowCtor(&context, WIDTH, HEIGHT, "Mandelbrot");

    sf::Time totalDrawTime   = sf::microseconds(0);
    sf::Time totalRenderTime = sf::microseconds(0);

    while (context.window.isOpen()) {
        windowHandleEvents(&context, &md);

        sf::Time t1 = clock.getElapsedTime();
        // calculateMandelbrotOptimized(md);
        calculateMandelbrotAutoVec(md);
        convertItersToColor(md);

        sf::Time t2 = clock.getElapsedTime();
        windowDraw(&context, md);

        sf::Time t3 = clock.getElapsedTime();
        total_rendered++;
        totalDrawTime   += t3 - t2;
        totalRenderTime += t2 - t1;
        fprintf(stderr, "\r%u; render: %d draw: %d" , total_rendered, (t2-t1).asMilliseconds(), (t3-t2).asMilliseconds());

    }

    printf("\n\nStats:\n");
    printf("Total frames: %u\n", total_rendered);
    printf("Mean render time: %.2f ms\n", (float) totalRenderTime.asMilliseconds() / total_rendered);
    printf("Mean draw   time: %.2f ms\n", (float) totalDrawTime.asMilliseconds()   / total_rendered);
    mdContextDtor(&md);
    return 0;
}


