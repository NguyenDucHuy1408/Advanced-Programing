#pragma once
#include "move.h"
#include "collision.h"
#include "sound.h"
#include "common.h"

class Game
{
public:
    Game();

    ~Game();

    void initGame();

    void playGame();

    void closeGame();

private:
    Common* common = nullptr;

    ScrollingBackground* background = nullptr;

    Sound* sound = nullptr;

    Move* hero = nullptr;

    TTF_Font* font = nullptr;
};
