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

    void randMonster();

    void moveMonster();

    SDL_Texture *texture;

    int x, y;

private:
    vector<SDL_Rect> clips;
    int currentFrame;
};
