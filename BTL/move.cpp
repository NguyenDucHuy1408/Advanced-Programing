#include "move.h"

Move::Move()
{

}

Move::~Move()
{

}

void Move::initHero()
{
    dstRect.x = 100;
    dstRect.y = SCREEN_HEIGHT - dstRect.w;
    vx = vy = 0;
}

void Move::handleEvent(SDL_Event e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: vy -= SPEED_HERO; break;
            case SDLK_DOWN: vy += SPEED_HERO; break;
            case SDLK_LEFT: vx -= SPEED_HERO; break;
            case SDLK_RIGHT: vx += SPEED_HERO; break;
        }
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: vy += SPEED_HERO; break;
            case SDLK_DOWN: vy -= SPEED_HERO; break;
            case SDLK_LEFT: vx += SPEED_HERO; break;
            case SDLK_RIGHT: vx -= SPEED_HERO; break;
        }
    }
}

void Move::move()
{
    dstRect.x += vx;
    if (dstRect.x < 0 || dstRect.x + dstRect.w > SCREEN_WIDTH)
        dstRect.x -= vx;

    dstRect.y += vy;
    if (dstRect.y < 0 || dstRect.y + dstRect.h > SCREEN_HEIGHT)
        dstRect.y -= vy;
}
