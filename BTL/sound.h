#pragma once
#include "defs.h"

class Sound
{
public:
    Sound();

    ~Sound();

    Mix_Music* loadMusic(const char* path);

    void playMusic(Mix_Music* music);

    Mix_Chunk* loadChunk(const char* path);

    void playChunk(Mix_Chunk* chunk);

private:

};
