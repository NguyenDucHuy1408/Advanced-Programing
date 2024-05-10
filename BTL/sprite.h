#pragma once
#include "defs.h"

class Sprite
{
public:
    Sprite();

    ~Sprite();

    void init(SDL_Texture *_texture, int frames, const int _clips[][4]);

    void tick();

    const SDL_Rect *getCurrentClip() const;

    SDL_Texture *texture;

private:
    vector<SDL_Rect> clips;
    int currentFrame;
};
