#include "sprite.h"
#include "common.h"

Sprite::Sprite(const char* file, int frames, int speed)
{
    texture = Common::loadTexture(file);

    this->frames = frames;
    this->speed = speed;

    SDL_QueryTexture(texture, NULL, NULL, &srcRect.w, &srcRect.h);

    srcRect.w /= frames;

    dstRect.w = srcRect.w;
    dstRect.h = srcRect.h;

    srcRect.x = srcRect.y = 0;
}

Sprite::~Sprite()
{

}

void Sprite::update()
{
    srcRect.x = srcRect.w * (int)((SDL_GetTicks() / speed) % frames);
}

void Sprite::render()
{
    Common::renderTexture(texture, &srcRect, &dstRect);
}

SDL_Rect* Sprite::getRect()
{
    return &dstRect;
}

void Sprite::setScale(double scale)
{
    dstRect.w *= scale;

    dstRect.h *= scale;
}
