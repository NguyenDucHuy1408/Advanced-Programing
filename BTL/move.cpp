#include "move.h"

Move::Move()
{
    x = 100;
    y = SCREEN_HEIGHT / 2 - 100;
    dx = 0;
    dy = 0;
    speed = SPEED_BIRD;
}

Move::~Move()
{

}

void Move::update()
{
    dx = 0;
    dy = 0;
}

void Move::move()
{
    x += dx;
    y += dy;
}

void Move::turnNorth()
{
    if(y <= 0) return;

    dx = 0;
    dy = -speed;
}

void Move::turnSouth()
{
    if(y >= SCREEN_HEIGHT - 150) return;

    dx = 0;
    dy = speed;
}

void Move::turnEast()
{
    if(x >= SCREEN_WIDTH - 100) return;

    dx = speed;
    dy = 0;
}

void Move::turnWest()
{
    if(x <= 0) return;

    dx = -speed;
    dy = 0;
}
