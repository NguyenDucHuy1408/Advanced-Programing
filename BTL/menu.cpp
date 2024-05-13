#include "menu.h"

Menu::Menu()
{
    sech = new Game();
    menuBg = Common::loadTexture(MENU_FILE);
}

Menu::~Menu()
{
    delete sech;
    SDL_DestroyTexture(menuBg);
}

void Menu::handleEvent()
{
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
        {
            sech->playGame();
            SDL_Delay(100);
        }
        if (e.type == SDL_QUIT)
        {
            isOpen = false;
        }
    }
}

void Menu::Update() {}

void Menu::Render()
{
    Common::renderTexture(menuBg);
    Common::presentScene();
}

bool Menu::Open() const { return isOpen; }

void Menu::randColor()
{
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}
