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

    static void renderMenu();

    void closeGame();

    static SDL_Texture* textureHeroRun;
    static SDL_Texture* textureHeroJumpAttack;

    static SDL_Texture* textureDemonFly;
    static SDL_Texture* textureDemonAttack;

    static SDL_Texture* mainMenu;
    SDL_Texture* gameover;

    static bool quit;
private:
    Common* common = nullptr;

    Sound* sound = nullptr;

    Mix_Music* soundtrack = nullptr;
    Mix_Music* menuMusic = nullptr;

    Mix_Chunk* killmonster = nullptr;
    Mix_Chunk* endgame = nullptr;

    ScrollingBackground* background = nullptr;

    Move* hero = nullptr;

    Monster* demon = nullptr;

    TTF_Font* font = nullptr;

    int distance;
};
