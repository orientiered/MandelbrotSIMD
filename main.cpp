#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <stdio.h>

#include <mandelbrot.h>
#include <window.h>

int main(int argc, const char *argv[]) {

    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    mdContext_t md = mdContextCtor(WIDTH, HEIGHT);


    bool test_mode = argc > 1;
    unsigned test_count = 0;
    if (test_mode) sscanf(argv[1], "%u", &test_count);

    uint32_t total_rendered = 0;

    sf::Clock clock;

    if (test_mode) {
        clock.restart();
        for (; total_rendered < test_count; total_rendered++) {
            calculateMandelbrot(md);
        }
        sf::Time elapsedTime = clock.getElapsedTime();
        printf("Unoptimized\nTest completed!\n\n");
        printf("Rendered %d frames within %.3f seconds\n", total_rendered, elapsedTime.asSeconds());
        printf("FPS = %.2f, MSPF = %.2f\n", (float)total_rendered / elapsedTime.asSeconds(),
                                            (float)elapsedTime.asMilliseconds() / total_rendered);

        total_rendered = 0;
        clock.restart();
        for (; total_rendered < test_count; total_rendered++) {
            calculateMandelbrotOptimized(md);
        }
        elapsedTime = clock.getElapsedTime();
        printf("Optimized\nTest completed!\n\n");
        printf("Rendered %d frames within %.3f seconds\n", total_rendered, elapsedTime.asSeconds());
        printf("FPS = %.2f, MSPF = %.2f\n", (float)total_rendered / elapsedTime.asSeconds(),
                                            (float)elapsedTime.asMilliseconds() / total_rendered);
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
        calculateMandelbrotOptimized(md);
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
    printf("Total frames: %d\n", total_rendered);
    printf("Mean render time: %.2f ms\n", (float) totalRenderTime.asMilliseconds() / total_rendered);
    printf("Mean draw   time: %.2f ms\n", (float) totalDrawTime.asMilliseconds()   / total_rendered);
    mdContextDtor(&md);
    return 0;
}


