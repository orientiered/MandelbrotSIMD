#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <stdio.h>

#include <mandelbrot.h>
#include <window.h>
#include <metrics.h>


int testMandelbrot(FILE *file, const mdContext_t md, const unsigned test_count, const sf::Time duration) {

    printf("Running unoptimized version...\n");
    testTime_t noOptTime = testMandelbrotFunction(calculateMandelbrot, md, test_count, duration);
    saveMandelbrotTestResult(file, noOptTime, "No optimizations");

    printf("\nRunning optimized version...\n");
    testTime_t optTime   = testMandelbrotFunction(calculateMandelbrotOptimized, md, test_count, duration);
    saveMandelbrotTestResult(file, optTime, "Intrinsic optimizations");

    printf("\nRunning autoVec version...\n");
    testTime_t autoVecTime   = testMandelbrotFunction(calculateMandelbrotAutoVec, md, test_count, duration);
    saveMandelbrotTestResult(file, autoVecTime, "Automatic vectorization by compiler");


    return 0;
}

int main(int argc, const char *argv[]) {
    typedef int (*mandelbrotFunc_t)(const mdContext_t md);
    const char *testsInfoFilename = "tests.md";
    const int WIDTH  = 1920;
    const int HEIGHT = 1080;
    const mandelbrotFunc_t mandelbrotRenderer = calculateMandelbrotOptimized;

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
        FILE *testRecords = fopen(testsInfoFilename, "a");
        fprintf(testRecords, "\n# Test session\n"
                             "## General information:\n"
                             "```\n"
                             "%s"
                             "```\n", infoString);

        testMandelbrot(testRecords, md, test_count, sf::seconds(0));
        mdContextDtor(&md);
        fclose(testRecords);
        return 0;
    }

    windowContext_t context;
    windowCtor(&context, md.WIDTH, md.HEIGHT, "Mandelbrot");

    sf::Time totalDrawTime   = sf::microseconds(0);
    sf::Time totalRenderTime = sf::microseconds(0);

    while (context.window.isOpen()) {
        windowHandleEvents(&context, &md);

        sf::Time t1 = clock.getElapsedTime();
        mandelbrotRenderer(md);
        sf::Time t2 = clock.getElapsedTime();

        convertItersToColor(md);
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


