#include "game.h"

Monster::Monster()
{
    texture = NULL;
    x = SCREEN_WIDTH;
    y = rand() % (SCREEN_HEIGHT - 150);
}

Monster::~Monster()
{

}

void Monster::setMonster(SDL_Texture *_texture)
{
    texture = _texture;
}

void Monster::moveMonster()
{
    x -= SPEED_MONSTER;
}

void Monster::randMonster()
{
    x = SCREEN_WIDTH;
    y = rand() % (SCREEN_HEIGHT - 150);
}
