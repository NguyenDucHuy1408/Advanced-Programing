#pragma once
#include "defs.h"
#include "sprite.h"

class Move : public Sprite
{
public:
    Move();

    ~Move();

    void handleEvent();

    void move();
private:
    SDL_Event e;
    int vx, vy;
};
