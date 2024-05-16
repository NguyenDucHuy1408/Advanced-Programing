#pragma once
#include "move.h"
#include "collision.h"
#include "sound.h"
#include "common.h"
#include "monster.h"

class Game
{
public:
    Game();

    ~Game();

    void initGame();

    void playGame();

    void closeGame();

    static SDL_Texture* textureHeroRun;
    static SDL_Texture* textureHeroJumpAttack;

    static SDL_Texture* textureDemonFly;
    static SDL_Texture* textureDemonAttack;

private:
    Common* common = nullptr;

    Sound* sound = nullptr;
    Mix_Music* soundtrack;
    Mix_Music* menuMusic;

    Mix_Chunk* chunk;

    ScrollingBackground* background = nullptr;

    Move* hero = nullptr;

    Monster* demon = nullptr;

    TTF_Font* font = nullptr;
};
