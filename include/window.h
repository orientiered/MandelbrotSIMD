#ifndef WINDOW_H
#define WINDOW_H

typedef struct {
    sf::RenderWindow window;
    sf::Texture mdTexture;
    sf::Sprite  mdSprite;

    sf::Vector2<double> oldMousePos;
    bool mousePressed;
} windowContext_t;

const double MD_SCALE_FACTOR = 0.8; // scale *= MD_SCALE_FACTOR
const double MD_ITERS_FACTOR = 1.1; // maxIter *= MD_ITERS_FACTOR
const double MD_MOVE_FACTOR  = 0.01; // move = WIDTH * scale * MD_MOVE_FACTOR

int windowCtor(windowContext_t *context, const int WIDTH, const int HEIGHT, const char *title);

int windowHandleEvents(windowContext_t *context, mdContext_t *md);

int windowDraw(windowContext_t *context, const mdContext_t md);

#endif
