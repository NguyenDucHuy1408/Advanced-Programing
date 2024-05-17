#pragma once
#include "defs.h"

class ScrollingBackground
{
public:
    ScrollingBackground();

    ~ScrollingBackground();

    void setTexture(SDL_Texture *_texture);

    void scroll(const int distance);

    SDL_Texture *texture;

    int scrollingOffset;

    int width, height;

private:

};
