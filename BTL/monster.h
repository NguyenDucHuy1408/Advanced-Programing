#pragma once
#include "sprite.h"

class Monster : public Sprite
{
public:
    Monster();

    ~Monster();

    void initMonster(int skills, int prepare);

    void moveMonster();

    bool checkDistance(SDL_Rect r);

    std::vector<SDL_Texture*> states;
private:
    int current, skills, prepare;
};
