#pragma once
#include "game.h"

class Menu {
public:
    Menu();

    ~Menu();

    void init();

    void handleEvent();

    void update();

    void render();

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
