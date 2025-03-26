#include <SFML/Graphics.hpp>
#include <mandelbrot.h>
#include <window.h>

int windowCtor(windowContext_t *context, const int WIDTH, const int HEIGHT, const char *title) {
    context->window.create(sf::VideoMode(WIDTH, HEIGHT), title);
    context->mdTexture.create(WIDTH, HEIGHT);
    context->mdSprite.setTexture(context->mdTexture, true);

    context->mousePressed = false;
    return 0;
}


int windowHandleEvents(windowContext_t *context, mdContext_t *md) {
    sf::Event event;
    while (context->window.pollEvent(event) ) {
        switch(event.type) {
            case sf::Event::Closed:
                context->window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    context->mousePressed = true;
                    context->oldMousePos.x = event.mouseButton.x;
                    context->oldMousePos.y = event.mouseButton.y;
                }
                break;

            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left) {
                   context->mousePressed = false;
                }
                break;

            case sf::Event::MouseMoved:
                if (context->mousePressed) {
                    md->centerX -= (event.mouseMove.x - context->oldMousePos.x) * md->scale;
                    md->centerY += (event.mouseMove.y - context->oldMousePos.y) * md->scale;
                    context->oldMousePos.x = event.mouseMove.x;
                    context->oldMousePos.y = event.mouseMove.y;
                }
                break;

            case sf::Event::MouseWheelScrolled:
            {
                md_float multiplier = (event.mouseWheelScroll.delta > 0) ? 0.8 : (-1.0/0.8);
                md->scale *= event.mouseWheelScroll.delta * multiplier;
                break;
            }

            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case sf::Keyboard::Up:
                        md->scale *= 0.8;
                        break;
                    case sf::Keyboard::Down:
                        md->scale *= 1.0/0.8;
                        break;
                    case sf::Keyboard::Escape:
                        context->window.close();
                        break;
                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }

    return 0;
}


int windowDraw(windowContext_t *context, const mdContext_t md) {
    context->mdTexture.update((sf::Uint8 *)md.screen);
    context->window.clear();
    context->window.draw(context->mdSprite);
    context->window.display();

    return 0;
}
