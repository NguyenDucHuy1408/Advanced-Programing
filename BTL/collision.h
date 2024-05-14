#pragma once
#include "defs.h"

class Collision
{
public:
    Collision();

    ~Collision();

    static bool inside(int x, int y, SDL_Rect r);

    static bool isOverLap(SDL_Rect r1, SDL_Rect r2);

private:

};
