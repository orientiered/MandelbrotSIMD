#ifndef WINDOW_H
#define WINDOW_H

typedef struct {
    sf::RenderWindow window;
    sf::Texture mdTexture;
    sf::Sprite  mdSprite;

    sf::Vector2<double> oldMousePos;
    bool mousePressed;
} windowContext_t;

int windowCtor(windowContext_t *context, const int WIDTH, const int HEIGHT, const char *title);

int windowHandleEvents(windowContext_t *context, mdContext_t *md);

int windowDraw(windowContext_t *context, const mdContext_t md);

#endif
