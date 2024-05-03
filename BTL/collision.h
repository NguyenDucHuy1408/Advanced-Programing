#pragma once
#include "defs.h"

bool inside(int x, int y, SDL_Rect r)
{
    return x >= r.x && y >= r.y && x <= r.x + r.w && y <= r.y + r.h;
}

bool isOverLap(SDL_Rect r1, SDL_Rect r2)
{
    return inside(r1.x, r1.y, r2) || inside(r1.x + r1.w, r1.y + r1.h, r2)
        || inside(r1.x, r1.y + r1.h, r2) || inside(r1.x + r1.w, r1.y, r2);
}

class Collision
{
public:
    SDL_Rect r;
private:
    int x, y, w, h;
};
