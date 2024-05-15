#include "menu.h"

Menu::Menu()
{
    game = new Game();
}

Menu::~Menu()
{
    delete game;
    game = nullptr;

    SDL_DestroyTexture(menuBg);
    menuBg = nullptr;
}

void Menu::init()
{
    game -> initGame();

    menuBg = Common::loadTexture(MENU_FILE);

    isOpen = true;
}

void Menu::handleEvent()
{
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
            game->playGame();

        if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
            isOpen = false;

        SDL_Delay(100);
    }
}

void Menu::update()
{

}

void Menu::render()
{
    Common::renderTexture(menuBg);
    Common::presentScene();
}

void Menu::close()
{
    game -> closeGame();
}

bool Menu::Open() const
{
    return isOpen;
}

void Menu::randColor()
{
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}
