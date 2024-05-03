#pragma once
#include "defs.h"
#include "sprite.h"
#include "map.h"
#include "game.h"

class Common
{
public:
    Common();
    ~Common();
    void logErrorAndExit(const char *msg, const char *error);
    void init();
    SDL_Texture *loadTexture(const char *file);
    void renderTexture(SDL_Texture *texture, int x, int y);
    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
    void prepareScene(SDL_Texture *background);
    void presentScene();
    SDL_Rect renderSprite(int x, int y, const Sprite &sprite);
    void renderScrollingBackground(const ScrollingBackground &background);
    SDL_Rect renderMonster(const Monster &monster);
    void quit();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};
