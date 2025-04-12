#include <SFML/Graphics.hpp>
#include <string.h>
#include <stdio.h>

#include "mandelbrot.h"

#include "window.h"
#include "metrics.h"


typedef struct {
    bool testMode;
    unsigned testCount;
    sf::Time testDuration;
} cmdArgsData_t;

static const unsigned DEFAULT_TEST_COUNT = 10;
static const float    DEFAULT_TEST_TIME  = 5.0; // seconds
cmdArgsData_t parseCmdArgs(int argc, const char *argv[]);



int main(int argc, const char *argv[]) {
    typedef int (*mandelbrotFunc_t)(const mdContext_t md);
    const char *testsInfoFilename = "test_results.md";
    const int WIDTH  = 1920;
    const int HEIGHT = 1080;
    const mandelbrotFunc_t mandelbrotRenderer = calculateMandelbrotThreaded;

    mdContext_t md = mdContextCtor(WIDTH, HEIGHT);

    threadPool_t threadPool;
    md.thrdPool = &threadPool;
    // thread pool is not initialized

    char infoString[512] = "";
    getProgramAndRunInfo(infoString, md);
    printf("%s\n", infoString);

    cmdArgsData_t cmdArgs = parseCmdArgs(argc, argv);

    uint32_t total_rendered = 0;

    sf::Clock clock;

    if (cmdArgs.testMode) {
        FILE *testRecords = fopen(testsInfoFilename, "a");
        fprintf(testRecords, "\n# Test session\n"
                             "## General information:\n"
                             "```\n"
                             "%s"
                             "```\n", infoString);

        testMandelbrot(testRecords, md, cmdArgs.testCount, cmdArgs.testDuration);
        mdContextDtor(&md);
        fclose(testRecords);
        return 0;
    }

    windowContext_t context;
    windowCtor(&context, md.WIDTH, md.HEIGHT, "Mandelbrot");
    
    /*==================================================*/
    if (mandelbrotRenderer == calculateMandelbrotThreaded)
        mdThreadPoolCtor(&threadPool, &md);
    /*==================================================*/


    sf::Time totalDrawTime   = sf::microseconds(0);
    sf::Time totalRenderTime = sf::microseconds(0);

    while (context.window.isOpen()) {
        windowHandleEvents(&context, &md);

        /*=================================*/
        sf::Time t1 = clock.getElapsedTime();
        mandelbrotRenderer(md);
        sf::Time t2 = clock.getElapsedTime();
        /*=================================*/

        convertItersToColor(md);
        windowDraw(&context, md);

        sf::Time t3 = clock.getElapsedTime();
        total_rendered++;
        totalDrawTime   += t3 - t2;
        totalRenderTime += t2 - t1;

        fpsMeterPushFrameTime(&context.fps, t3-t1);

        fprintf(stderr, "\r%u; render: %d draw: %d" , total_rendered, (t2-t1).asMilliseconds(), (t3-t2).asMilliseconds());

    }

    printf("\n\nStats:\n");
    printf("Total frames: %u\n", total_rendered);
    printf("Mean render time: %.2f ms\n", (float) totalRenderTime.asMilliseconds() / total_rendered);
    printf("Mean draw   time: %.2f ms\n", (float) totalDrawTime.asMilliseconds()   / total_rendered);
    mdContextDtor(&md);

    /*==================================================*/
    if (mandelbrotRenderer == calculateMandelbrotThreaded)
        mdThreadPoolDtor(&threadPool);
    /*==================================================*/

    return 0;
}


cmdArgsData_t parseCmdArgs(int argc, const char *argv[]) {
    cmdArgsData_t data = {false, 0, sf::Time::Zero};

    if (argc <= 1)
        return data;

    if (strcmp(argv[1], "--test") == 0) {
        float durationInSeconds = 0.;

        data.testMode = true;
        if (argc == 2) {
            printf("Using default test parameters: testCount = %u, time = %f sec\n", DEFAULT_TEST_COUNT, DEFAULT_TEST_TIME);
            data.testCount = DEFAULT_TEST_COUNT;
            data.testDuration = sf::seconds(DEFAULT_TEST_TIME);
        }

        for (int argvIndex = 2; argvIndex < argc; argvIndex++) {
            if (sscanf(argv[argvIndex], "-number=%u", &data.testCount) == 1)
                continue;

            if (sscanf(argv[argvIndex], "-time=%f", &durationInSeconds) == 1) {
                data.testDuration = sf::seconds(durationInSeconds);
                continue;
            }

            printf("Expected: -number=<unsigned number of tests> || -time=<float number of seconds>\n");
            printf("Got: %s\n", argv[argvIndex]);
            printf("Deactivating test mode\n");
            data.testMode = false;

            break;
        }
    } else if (strcmp(argv[1], "--help") == 0) {
        printf( "# Mandelbrot set explorer                              \n"
                "$ Flags description:                                   \n"
                "! --help  see this message                             \n"
                "! --test  activate testing mode                        \n"
                "! After --test: -number=<unsigned number of tests>      \n"
                "!               -time=<float number of seconds>         \n"
                "$ Example: ./mandelbrot.exe --test time=5.6 number=30  \n");
    }

    return data;
}
