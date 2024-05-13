#include "menu.h"

void waitUntilKeyPressed()
{
    SDL_Event e;
    while(true) {
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_KEYDOWN)
                return;
            SDL_Delay(100);
        }
    }
}

int main(int argc, char *argv[])
{
    srand(time(0));
    Menu* sech = new Menu();

    while (sech->Open())
    {
        sech->handleEvent();
        sech->Render();
    }
    return 0;
}
