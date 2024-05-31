#include "boss.h"

SDL_Texture* Boss::textureBossIdle = nullptr;
SDL_Texture* Boss::textureBossVanish = nullptr;
SDL_Texture* Boss::textureBossShriek = nullptr;

Boss::Boss()
{
    textureBossIdle = Common::loadTexture(BOSS_IDLE_FILE);
    textureBossVanish = Common::loadTexture(BOSS_VANISH_FILE);
    textureBossShriek = Common::loadTexture(BOSS_SHRIEK_FILE);
}

Boss::~Boss()
{

}

void Boss::initBoss()
{
    dstRect.x = SCREEN_WIDTH - 500;
    dstRect.y = SCREEN_HEIGHT - dstRect.h;
    STATE = IDLE;
    hpHero = HP_HERO;
}

void Boss::update()
{
//    if (STATE != IDLE) if (srcRect.x == srcRect.w - srcRect.h) {
//        STATE = static_cast<BOSS_STATE>((STATE + 1) % 4);
//        std::cout << static_cast<int>(STATE) << "\n";
//    }
    srcRect.x = srcRect.w * (int)(((SDL_GetTicks() - currentTime) / speed) % frames);
}

void Boss::moveBoss(SDL_Rect hero)
{

    if (SDL_GetTicks() - time >= 400 && STATE == IDLE) {
        init(textureBossIdle, 7, 100, 0);
        time = SDL_GetTicks();
        STATE = VANISH;
    }
    else if (SDL_GetTicks() - time >= 2100 && STATE == VANISH) {
        init(textureBossVanish, 7, 100, 0);
        time = SDL_GetTicks();
        STATE = INVISIBLE;
    }
    else if (SDL_GetTicks() - time >= 700 && STATE == INVISIBLE) {
        time = SDL_GetTicks();
        STATE = SHRIEK;
    }
    else if (SDL_GetTicks() - time >= 2100 && STATE == SHRIEK) {
        init(textureBossShriek, 4, 100, 0);
        dstRect.x = hero.x;
        time = SDL_GetTicks();
        STATE = IDLE;
        hpHero -= 20;
    }
}
