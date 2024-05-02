#include "move.h"

Move::Move()
{
    x = 100;
    y = SCREEN_HEIGHT / 2 - 100;
    dx = 0;
    dy = 0;
    speed = SPEED;
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
    dx = 0;
    dy = -speed;
}

void Move::turnSouth()
{
    dx = 0;
    dy = speed;
}

void Move::turnEast()
{
    dx = speed;
    dy = 0;
}

void Move::turnWest()
{
    dx = -speed;
    dy = 0;
}
