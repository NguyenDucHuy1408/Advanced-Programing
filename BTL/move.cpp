#include "move.h"
#include "game.h"

Move::Move()
{

}

Move::~Move()
{

}

void Move::initHero()
{
    dstRect.x = 100;
    dstRect.y = SCREEN_HEIGHT - dstRect.h;
    vx = vy = 0;
}

void Move::handleEvent(SDL_Event e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_SPACE: init(Game::textureHeroJumpAttack, 6, 100); check = false; break;
            case SDLK_LEFT: vx -= SPEED_HERO; break;
            case SDLK_RIGHT: vx += SPEED_HERO; break;
            case SDLK_p: {
                Game::renderMenu();
                break;
            }
        }
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_SPACE: init(Game::textureHeroJumpAttack, 6, 100); check = false; break;
            case SDLK_LEFT: vx += SPEED_HERO; break;
            case SDLK_RIGHT: vx -= SPEED_HERO; break;
            case SDLK_p: Game::renderMenu(); break;
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
