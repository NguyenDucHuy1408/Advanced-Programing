#pragma once
#include "monster.h"

enum BOSS_STATE
{
    IDLE,
    VANISH,
    INVISIBLE,
    SHRIEK
};

class Boss : public Monster
{
public:
    Boss();

    ~Boss();

    void initBoss();

    void moveBoss(SDL_Rect hero);

    void update();

    BOSS_STATE STATE;

    int hpHero;

private:
    Uint32 time;

    static SDL_Texture* textureBossIdle;
    static SDL_Texture* textureBossVanish;
    static SDL_Texture* textureBossShriek;
};
