#pragma once
#include "game.h"

class Menu {
public:
    Menu();

    ~Menu();

    void init();

    void handleEvent();

    void Update();

    void Render();

    void close();

    void randColor();

    int r, g, b;

    bool Open() const;

private:
    Game* game = NULL;

    SDL_Texture* menuBg = NULL;

    bool isOpen;

    SDL_Event e;
};
