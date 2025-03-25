#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <stdio.h>

typedef struct color{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} color_t;

int calculateMandelbrot(uint32_t *pixels, const unsigned WIDTH, const unsigned HEIGHT, const float scale);

const float MANDELBROT_WIDTH  = 3.0;
float MANDELBROT_HEIGHT = 2.0;


int main(int argc, const char *argv[]) {

    const unsigned WIDTH = 2000;
    const unsigned HEIGHT = 1200;

    MANDELBROT_HEIGHT = MANDELBROT_WIDTH * HEIGHT / WIDTH;

    bool test_mode = argc > 1;
    int  test_count = 0;
    if (test_mode) sscanf(argv[1], "%d", &test_count);

    uint32_t *screen = (uint32_t *) calloc(WIDTH * HEIGHT, sizeof(uint32_t) );

    uint32_t total_rendered = 0;

    if (test_mode) {
        for (; total_rendered < test_count; total_rendered++) {
            calculateMandelbrot(screen, WIDTH, HEIGHT, 1.0);
        }
        free(screen);
        return 0;
    }

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Mandelbrot");



    sf::Texture mandelbrot;
    mandelbrot.create(WIDTH, HEIGHT);

    sf::Sprite  mandelbrot_sprite;
    mandelbrot_sprite.setTexture(mandelbrot, true);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event) ) {
            if (event.type ==sf::Event::Closed) {
                window.close();
                break;
            }
        }


        calculateMandelbrot(screen, WIDTH, HEIGHT, 1.0);

        window.clear();
        fprintf(stderr, "1Calc");

        mandelbrot.update((sf::Uint8 *)screen);
        fprintf(stderr, "2Upd");

        window.draw(mandelbrot_sprite);
        window.display();
        fprintf(stderr, "3Draw");

        total_rendered++;
        fprintf(stderr, "\r%u        " , total_rendered);

    }


    free(screen);
    return 0;
}


int calculateMandelbrot(uint32_t *pixels, const unsigned WIDTH, const unsigned HEIGHT, const float scale) {
    const uint32_t MAX_ITER = 256;
    const float ESCAPE_RADIUS2 = 100.f;

    for (unsigned iy = 0; iy < HEIGHT; iy++) {
        float x0 = -2 * scale,
              y0 = (MANDELBROT_HEIGHT / 2 - (float)(iy) / HEIGHT * MANDELBROT_HEIGHT) * scale;

        float dx = MANDELBROT_WIDTH / WIDTH * scale;
        for (unsigned ix = 0; ix < WIDTH; ix++, x0 += dx) {
            /*
                z' = z^2 + z_0 = (x+iy)^2 + x_0 + iy_0 = x^2 - y^2 + x_0 + i(2x*y + y_0)
                x' = x^2 - y^2 + x0
                y' = 2xy + y_0
            */
            float x = x0, y = y0;

            uint32_t iter = 0;
            for (; iter < MAX_ITER; iter++) {
                float x2 = x*x, y2 = y*y, xy_2 = 2*x*y;
                if (x2 + y2 > ESCAPE_RADIUS2)
                    break;

                x = x2 - y2 + x0;
                y = xy_2    + y0;
            }

            pixels[iy*WIDTH+ix] = (iter == MAX_ITER) ?
                                    sf::Color::Black.toInteger() :
                                    sf::Color(MAX_ITER-iter, iter/2*3, iter%5*64).toInteger();
        }
    }
    return 0;
}
