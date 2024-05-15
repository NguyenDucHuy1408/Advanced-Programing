#include "common.h"

SDL_Renderer* Common::renderer = nullptr;

Common::Common()
{
    window = nullptr;
    renderer = nullptr;
}

Common::~Common()
{

}

void Common::logErrorAndExit(const char *msg, const char *error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

void Common::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING))
        logErrorAndExit("SDL_Init", SDL_GetError());

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr)
        logErrorAndExit("CreateWindow", SDL_GetError());

    if(!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
        logErrorAndExit("IMG_Init", IMG_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr)
        logErrorAndExit("CreateRenderer", SDL_GetError());

    //Dặt chất lượng mở rộng/kéo nhỏ của texture khi vẽ lên renderer. “linear” có nghĩa là sẽ sử dụng phép lọc tuyến tính.
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    //Dặt kích thước logic cho renderer, giúp đơn giản hóa việc vẽ đồ họa khi màn hình có độ phân giải khác nhau.
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    //SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        logErrorAndExit("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());

    Mix_Volume(-1, 128);

    if (TTF_Init() == -1)
        logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ", TTF_GetError());
}

SDL_Texture *Common::loadTexture(const char *file)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                   "Loading img: %s", file);

    SDL_Texture *texture = IMG_LoadTexture(renderer, file);
    if(texture == nullptr)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Load texture %s", IMG_GetError());

    return texture;
}

void Common::renderTexture(SDL_Texture *texture, int x, int y)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;

    SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

void Common::renderTexture(SDL_Texture* texture, SDL_Rect *src, SDL_Rect *dst)
{
    SDL_RenderCopy(renderer, texture, src, dst);
}

void Common::blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y)
{

    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = src -> w;
    dest.h = src -> h;

    SDL_RenderCopy(renderer, texture, src, &dest);
}

void Common::prepareScene(SDL_Texture *background)
{
    SDL_RenderClear(renderer);

    if(background != nullptr)
        SDL_RenderCopy(renderer, background, nullptr, nullptr);
}

void Common::presentScene()
{
    SDL_RenderPresent(renderer);
}

void Common::renderScrollingBackground(const ScrollingBackground &background)
{
    renderTexture(background.texture, background.scrollingOffset, 0);
    renderTexture(background.texture, background.scrollingOffset - background.width, 0);
}

TTF_Font* Common::loadFont(const char* path, int size)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                   "Loading font: %s", path);

    TTF_Font* font = TTF_OpenFont(path, size);
    if(font == nullptr)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Could not open: %s", TTF_GetError());

    return font;
}

SDL_Texture* Common::fontTexture(const char* text, TTF_Font* font, SDL_Color textColor)
{
    if(font == nullptr) return nullptr;

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    if(textSurface == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Surface error: %s", TTF_GetError());
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if(texture == nullptr)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Texture error: %s", SDL_GetError());

    return texture;
}

void Common::quit()
{
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    SDL_Quit();
}
