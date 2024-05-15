#pragma once
#include "defs.h"

class Sprite
{
public:
    Sprite();

    Sprite(const char* file, int frames, int speed);

    ~Sprite();

    void update();

    void render();

    SDL_Rect* getRect();

    void setScale(double scale);

protected:
    SDL_Rect dstRect, srcRect;

    SDL_Texture* texture;

    int frames, speed;
};
