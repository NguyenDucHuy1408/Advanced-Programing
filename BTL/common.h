#pragma once
#include "defs.h"
#include "sprite.h"
#include "map.h"

class Common
{
public:
    Common();

    ~Common();

    void logErrorAndExit(const char *msg, const char *error);

    void init();

    static SDL_Texture* loadTexture(const char *file);

    static void renderTexture(SDL_Texture *texture, int x, int y);

    static void renderTexture(SDL_Texture* texture, SDL_Rect* src = nullptr, SDL_Rect* dst = nullptr);

    //static void renderTexture(SDL_Texture* texture, SDL_Rect* src = nullptr, SDL_Rect* dst = nullptr, )

    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);

    void prepareScene(SDL_Texture *background);

    static void presentScene();

    void renderScrollingBackground(const ScrollingBackground &background);

    TTF_Font* loadFont(const char* path, int size);

    SDL_Texture* fontTexture(const char* text, TTF_Font* font, SDL_Color textColor);

    static SDL_Renderer *renderer;

    void quit();

private:
    SDL_Window *window;
};
