#include "map.h"

ScrollingBackground::ScrollingBackground()
{
    texture = NULL;
    scrollingOffset = 0;
}

ScrollingBackground::~ScrollingBackground()
{

}

void ScrollingBackground::setTexture(SDL_Texture *_texture)
{
    texture = _texture;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void ScrollingBackground::scroll(const int distance)
{
    scrollingOffset -= distance;
    if(scrollingOffset < 0)
        scrollingOffset = width;
}
