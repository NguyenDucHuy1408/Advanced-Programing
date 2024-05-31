#include "sprite.h"
#include "common.h"

Sprite::Sprite()
{
    check = true;
}

Sprite::~Sprite()
{

}

void Sprite::init(SDL_Texture* texture, int frames, int speed, int h)
{
    this->frames = frames;
    this->speed = speed;
    this->texture = texture;

    SDL_QueryTexture(texture, nullptr, nullptr, &srcRect.w, &srcRect.h);

    w = srcRect.w * (frames - 1) / frames;
    srcRect.w /= frames;

    dstRect.w = srcRect.w;
    dstRect.h = srcRect.h;

    //dstRect.x = SCREEN_WIDTH;
    dstRect.y = SCREEN_HEIGHT - dstRect.h - h;

    srcRect.x = srcRect.y = 0;
    currentTime = SDL_GetTicks();
}

void Sprite::update()
{
    srcRect.x = srcRect.w * (int)(((SDL_GetTicks() - currentTime) / speed) % frames);
}

void Sprite::render()
{
    Common::renderTexture(texture, &srcRect, &dstRect);
}
