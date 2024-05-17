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

    bool Open() const;

private:
    Game* game = nullptr;

    SDL_Texture* menuBg = nullptr;

    bool isOpen;

    SDL_Event e;
};
