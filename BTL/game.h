#pragma once
#include "defs.h"

class Monster
{
public:
    Monster();

    ~Monster();

    void setMonster(SDL_Texture *_texture);

    void moveMonster();

    void randMonster();

    SDL_Texture *texture;

    int x, y;

private:
};
