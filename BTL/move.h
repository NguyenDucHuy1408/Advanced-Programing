#pragma once
#include "defs.h"
#include "sprite.h"

class Move : public Sprite
{
public:
    Move();

    ~Move();

    void initHero();

    void handleEvent(SDL_Event e);

    void move();

private:
    int vx, vy;
};
