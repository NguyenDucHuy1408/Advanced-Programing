#pragma once
#include "sprite.h"

class Monster : public Sprite
{
public:
    Monster();

    ~Monster();

    void initMonster();

    void moveMonster();

    bool checkDistance(SDL_Rect r);

    int state;

    int hpMonster;

    int currentHpMonster;

private:
    int prepare;
};
