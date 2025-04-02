#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Clipboard.hpp>
#include <stdlib.h>
#include <mandelbrot.h>
#include <window.h>

int windowCtor(windowContext_t *context, const int WIDTH, const int HEIGHT, const char *title) {
    context->window.create(sf::VideoMode(WIDTH, HEIGHT), title);
    context->mdTexture.create(WIDTH, HEIGHT);
    context->mdSprite.setTexture(context->mdTexture, true);

    context->mousePressed = false;
    return 0;
}

int windowHandleKeypress(windowContext_t *context, mdContext_t *md, const sf::Event::KeyEvent key) {
    double centerMove = md->WIDTH * MD_MOVE_FACTOR * md->scale;
    if (key.shift) centerMove *= MD_SHIFT_MOVE_FACTOR;

    switch(key.code) {
        case sf::Keyboard::W:
            md->centerY += centerMove;
            break;
        case sf::Keyboard::A:
            md->centerX -= centerMove;
            break;
        case sf::Keyboard::S:
            md->centerY -= centerMove;
            break;
        case sf::Keyboard::D:
            md->centerX += centerMove;
            break;

        case sf::Keyboard::Up:
            md->scale *= MD_SCALE_FACTOR;
            break;
        case sf::Keyboard::Down:
            md->scale *= 1./MD_SCALE_FACTOR;
            break;
        case sf::Keyboard::Left:
        {
            const int newMaxIter = (int)(md->maxIter * (1./MD_ITERS_FACTOR));
            if (MD_DEFAULT_MAX_ITER <= newMaxIter) {
                md->maxIter = newMaxIter;
                precalculateColors(*md);
            }
            break;
        }
        case sf::Keyboard::Right:
        {
            const int newMaxIter = (int)(md->maxIter * MD_ITERS_FACTOR);
            if (newMaxIter <= MD_ITERS_LIMIT) {
                md->maxIter = newMaxIter;
                precalculateColors(*md);
            }
            break;
        }
        case sf::Keyboard::Escape:
            context->window.close();
            break;

        case sf::Keyboard::C:
        {
        // Ctrl + C copies current position and scale to the clipboard
            const int MD_POS_SCALE_ACCURACY = 15;
            if (key.control) {
                char pos[MD_POS_SCALE_ACCURACY*4] = "";
                sprintf(pos, "%.*f %.*f %.*f",  MD_POS_SCALE_ACCURACY, md->centerX,
                                                MD_POS_SCALE_ACCURACY, md->centerY,
                                                MD_POS_SCALE_ACCURACY, md->scale);
                sf::Clipboard::setString(pos);
            }
            break;
        }
        case sf::Keyboard::V:
        {
        // Ctrl + V pastes position and scale from the clipboard
            if (key.control) {
                // Getting string from clipboard and converting to mbs
                sf::String pastedString = sf::Clipboard::getString();
                const uint32_t *posWstring = pastedString.getData();
                char posString[256] = "";
                wcstombs(posString, (const wchar_t *) posWstring, 256);

                // printf("Ctrl+V:%s\n\n\n", posString);
                double centerX = 0, centerY = 0, scale = 0;
                if (sscanf(posString, "%lf %lf %lf", &centerX, &centerY, &scale) == 3) {
                    md->centerX = centerX;
                    md->centerY = centerY;
                    md->scale   = scale;
                }
            }
            break;
        }
        default:
            break;
    }

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
                md_float multiplier = (event.mouseWheelScroll.delta > 0) ? MD_SCALE_FACTOR : (-1.0/MD_SCALE_FACTOR);
                md->scale *= event.mouseWheelScroll.delta * multiplier;
                break;
            }

            case sf::Event::KeyPressed:
                windowHandleKeypress(context, md, event.key);
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
