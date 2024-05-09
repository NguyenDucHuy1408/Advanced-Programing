#include "menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::randColor()
{
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}
