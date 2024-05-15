#include "move.h"

Move::Move()
{
    x = 100;
    y = SCREEN_HEIGHT - 96;
    dx = 0;
    dy = 0;
    speed = SPEED_HERO;
    hero = new Sprite(HERO_RUN_FILE, 12, 100);
    hero->setScale(2.0);
}

Move::~Move()
{
    delete hero;
}

void Move::update()
{
    dx = 0;
    dy = 0;
    hero->dstRect.x = x;
    hero->dstRect.y = y;
    hero->update();
    hero->render();
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
    if(y >= SCREEN_HEIGHT - hero->dstRect.h) return;

    dx = 0;
    dy = speed;
}

void Move::turnEast()
{
    if(x >= SCREEN_WIDTH - hero->dstRect.w) return;

    dx = speed;
    dy = 0;
}

void Move::turnWest()
{
    if(x <= 0) return;

    dx = -speed;
    dy = 0;
}

void Move::checkEvent()
{
    currentKeyStates = SDL_GetKeyboardState(NULL);

    if(currentKeyStates[SDL_SCANCODE_UP]) turnNorth();
    if(currentKeyStates[SDL_SCANCODE_DOWN]) turnSouth();
    if(currentKeyStates[SDL_SCANCODE_LEFT]) turnWest();
    if(currentKeyStates[SDL_SCANCODE_RIGHT]) turnEast();
}
