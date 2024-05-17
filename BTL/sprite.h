#pragma once
#include "defs.h"

class Sprite
{
public:
    Sprite();

    ~Sprite();

    void init(SDL_Texture* texture, int frames, int speed);

    void update();

    void render();

    int w;

    bool check;

    SDL_Rect dstRect, srcRect;

protected:
    SDL_Texture* texture;

    int frames, speed;

    int currentTime;
};
