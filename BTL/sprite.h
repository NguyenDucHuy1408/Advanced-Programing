#pragma once
#include "defs.h"

class Sprite
{
public:
    Sprite(const char* file, int frames, int speed);

    ~Sprite();

    void update();

    void render();

    SDL_Rect* getRect();

    void setScale(double scale);

    SDL_Rect dstRect;

protected:
    SDL_Rect srcRect;

    SDL_Texture* texture;

    int frames, speed;
};
