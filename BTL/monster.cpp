#include "monster.h"

Monster::Monster()
{

}

Monster::~Monster()
{

}

void Monster::initMonster(int skills, int prepare)
{
    this->skills = skills;
    this->prepare = prepare;
    dstRect.x = SCREEN_WIDTH;
    dstRect.y = SCREEN_HEIGHT - srcRect.h;
    current = 0;
}

void Monster::moveMonster()
{
    dstRect.x -= SPEED_MONSTER;
}

bool Monster::checkDistance(SDL_Rect r)
{
    return r.x + r.w + prepare * SPEED_MONSTER >= dstRect.x;
}
