#pragma once
#include "move.h"
#include "collision.h"
#include "sound.h"
#include "common.h"
#include "monster.h"
#include "savescore.h"
#include "boss.h"

class Game
{
public:
    Game();

    ~Game();

    void initGame();

    void playGame();

    void healthBar(int x, int y, int w, int h, int maxHealth, int currentHealth, int r, int g, int b);

    static void renderMenu();

    void closeGame();

    static SDL_Texture* textureHeroRun;
    static SDL_Texture* textureHeroJumpAttack;

    static SDL_Texture* textureDemonFly;
    static SDL_Texture* textureDemonAttack;

    static SDL_Texture* textureSkull;
    static SDL_Texture* textureFireSkull;

    static SDL_Texture* mainMenu;
    SDL_Texture* gameover;

    static bool quit;
private:
    Common* common = nullptr;

    static Sound* sound;

    static Mix_Music* soundtrack;
    static Mix_Music* menuMusic;

    static Mix_Chunk* bleed;
    static Mix_Chunk* killmonster;
    static Mix_Chunk* endgame;

    ScrollingBackground* background = nullptr;

    Move* hero = nullptr;

    Monster* monster = nullptr;

    Boss* boss = nullptr;

    TTF_Font* font = nullptr;

    TTF_Font* bigFont = nullptr;

    int distance;

    int highscore;

    Save* save = nullptr;

    static bool checkSound;
};
