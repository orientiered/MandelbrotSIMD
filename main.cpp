#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <stdio.h>

typedef struct color{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} color_t;

typedef struct {
    sf::Vector2f oldPosition;
    bool pressed;
} mouseState_t;

int calculateMandelbrot(uint32_t *pixels,
                        const float centerX, const float centerY,
                        const float scale,  // length per pixel
                        const int WIDTH, const int HEIGHT);



int main(int argc, const char *argv[]) {

    const int WIDTH = 800;
    const int HEIGHT = 600;

    const float MANDELBROT_WIDTH  = 3.0;
    float scale = MANDELBROT_WIDTH / WIDTH;
    float centerX = -0.5, centerY = 0;  // coordinated of the center point on screen

    mouseState_t mouseState = {{0,0}, false};

    bool test_mode = argc > 1;
    int  test_count = 0;
    if (test_mode) sscanf(argv[1], "%d", &test_count);

    uint32_t *screen = (uint32_t *) calloc(WIDTH * HEIGHT, sizeof(uint32_t) );

    uint32_t total_rendered = 0;

    if (test_mode) {
        for (; total_rendered < test_count; total_rendered++) {
            calculateMandelbrot(screen, centerX, centerY, scale, WIDTH, HEIGHT);
        }
        free(screen);
        return 0;
    }


    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Mandelbrot"); // creating window


    sf::Texture mandelbrot;             // screen texture
    mandelbrot.create(WIDTH, HEIGHT);

    sf::Sprite  mandelbrot_sprite;
    mandelbrot_sprite.setTexture(mandelbrot, true);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event) ) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mouseState.pressed = true;
                    mouseState.oldPosition.x = event.mouseButton.x;
                    mouseState.oldPosition.y = event.mouseButton.y;
                }
            } else
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mouseState.pressed = false;
                }
            } else
            if (event.type == sf::Event::MouseMoved) {
                if (mouseState.pressed) {
                    centerX -= (event.mouseMove.x - mouseState.oldPosition.x) * scale;
                    centerY += (event.mouseMove.y - mouseState.oldPosition.y) * scale;
                    mouseState.oldPosition.x = event.mouseMove.x;
                    mouseState.oldPosition.y = event.mouseMove.y;
                }
            } else
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0) {
                    scale *= 0.8 * event.mouseWheelScroll.delta;
                } else {
                    scale *= -(1.0/0.8) * event.mouseWheelScroll.delta;
                }
            } else
            if (event.type == sf::Event::KeyPressed) {
                switch(event.key.code) {
                    case sf::Keyboard::Up:
                        scale *= 0.8;
                        break;
                    case sf::Keyboard::Down:
                        scale *= 1.0/0.8;
                        break;
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    default:
                        break;
                }
            }
        }


        calculateMandelbrot(screen, centerX, centerY, scale, WIDTH, HEIGHT);

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


int calculateMandelbrot(uint32_t *pixels,
                        const float centerX, const float centerY,
                        const float scale,
                        const int WIDTH, const int HEIGHT) {

    const int MAX_ITER = 256;
    const float ESCAPE_RADIUS2 = 100.f;

    for (int iy = 0; iy < HEIGHT; iy++) {
        float x0 = centerX - scale * WIDTH / 2,
              y0 = centerY + (HEIGHT/2 - iy) * scale;
        float dx = scale;

        for (int ix = 0; ix < WIDTH; ix++, x0 += dx) {
            /*
                z' = z^2 + z_0 = (x+iy)^2 + x_0 + iy_0 = x^2 - y^2 + x_0 + i(2x*y + y_0)
                x' = x^2 - y^2 + x0
                y' = 2xy + y_0
            */
            float x = x0, y = y0;

            int iter = 0;
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
