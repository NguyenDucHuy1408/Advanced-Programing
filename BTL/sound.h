#pragma once
#include "defs.h"

class Sound
{
public:
    Sound();
    ~Sound();
    Mix_Music* loadMusic(const char* path);
    void playMusic();
    Mix_Chunk* loadChunk(const char* path);
    void playChunk();
private:
    Mix_Music *music;
    Mix_Chunk *chunk;
};
