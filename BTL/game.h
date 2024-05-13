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
    Common* common = NULL;

    Sound* sound = NULL;

    Sprite* bird = NULL;

    Sprite* ragnarok = NULL;

    Move* mouse = NULL;

};
