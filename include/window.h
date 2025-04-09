#ifndef WINDOW_H
#define WINDOW_H

// #include <SFML/Graphics/Text.hpp>


#include <SFML/Graphics/RenderWindow.hpp>
const int FRAME_AVERAGING_COUNT = 10;

typedef struct {
    sf::Font font;
    sf::Text FPS;

    sf::Time frameTimes[FRAME_AVERAGING_COUNT];
} FPSmeter_t;

typedef struct {
    sf::RenderWindow window;
    sf::Texture mdTexture;
    sf::Sprite  mdSprite;

    FPSmeter_t fps;

    sf::Vector2<double> oldMousePos;
    bool mousePressed;

    
} windowContext_t;

const char * const FONT_FILENAME = "docs/Orbitron-VariableFont_wght.ttf";

const double MD_SCALE_FACTOR = 0.8; // scale *= MD_SCALE_FACTOR
const double MD_ITERS_FACTOR = 1.1; // maxIter *= MD_ITERS_FACTOR
const double MD_MOVE_FACTOR  = 0.01; // move = WIDTH * scale * MD_MOVE_FACTOR
const double MD_SHIFT_MOVE_FACTOR = 10; // move *= MD_SHIFT_MOVE_FACTOR when shift is pressed

int fpsMeterCtor(FPSmeter_t *fps, const sf::Vector2f pos, const char *fontPath);
int fpsMeterPushFrameTime(FPSmeter_t *fps, const sf::Time lastFrameTime);
int fpsMeterDraw(FPSmeter_t *fps, sf::RenderWindow *window);

int windowCtor(windowContext_t *context, const int WIDTH, const int HEIGHT, const char *title);

int windowHandleEvents(windowContext_t *context, mdContext_t *md);

int windowDraw(windowContext_t *context, const mdContext_t md);

#endif
