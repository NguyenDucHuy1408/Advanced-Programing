#include "monster.h"

Monster::Monster()
{
    dstRect.x = SCREEN_WIDTH;
    state = rand() % 2;
    if (state == 0)
        hpMonster = HP_DEMON;
    else if (state == 1)
        hpMonster = HP_SKULL;
    prepare = 15;
    currentHpMonster = hpMonster;
}

Monster::~Monster()
{

}

void Monster::initMonster()
{
    dstRect.x = SCREEN_WIDTH;
    if (state == 0)
        hpMonster = HP_DEMON;
    else if (state == 1)
        hpMonster = HP_SKULL;
    currentHpMonster = hpMonster;
}

void Monster::moveMonster()
{
    dstRect.x -= SPEED_MONSTER;
}

bool Monster::checkDistance(SDL_Rect r)
{
    return r.x + r.w + prepare * SPEED_MONSTER >= dstRect.x && r.x <= dstRect.x;
}
