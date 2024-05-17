#pragma once
#include "sprite.h"

class Monster : public Sprite
{
public:
    Monster();

    ~Monster();

    void initMonster(int prepare);

    void moveMonster();

    bool checkDistance(SDL_Rect r);

private:
    int prepare;
};
