#pragma once
#include "game.h"

class Menu {
public:
    Menu();

    ~Menu();

    void handleEvent();

    void Update();

    void Render();

    void randColor();

    int r, g, b;

    bool Open() const;

private:
    Game* sech = nullptr;

    SDL_Texture* menuBg = nullptr;

    bool isOpen = true;
    SDL_Event e;
};
