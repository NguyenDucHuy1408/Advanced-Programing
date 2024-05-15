#include "sound.h"

Sound::Sound()
{

}

Sound::~Sound()
{

}

Mix_Music* Sound::loadMusic(const char* path)
{
    Mix_Music *music;
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading music: %s", path);

    music = Mix_LoadMUS(path);
    if(music == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Could not load music! SDL_mixer Error: %s", Mix_GetError());

    return music;
}

void Sound::playMusic(Mix_Music *music)
{
    if(music == NULL) return;

    if(Mix_PlayingMusic() == 0)
        Mix_PlayMusic(music, -1);

    else if(Mix_PausedMusic() == 1)
        Mix_ResumeMusic();
}

Mix_Chunk* Sound::loadChunk(const char* path)
{
    Mix_Chunk *chunk;
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading chunk: %s", path);

    chunk = Mix_LoadWAV(path);
    if(chunk == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Could not load chunk! SDL_mixer Error: %s", Mix_GetError());

    return chunk;
}

void Sound::playChunk(Mix_Chunk *chunk)
{
    if(chunk != NULL)
        Mix_PlayChannel(-1, chunk, 0);
}
