#include "defs.h"
#include "common.h"
#include "sprite.h"
#include "move.h"
#include "collision.h"
#include "sound.h"

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
    Common hehe;
    hehe.init();

    Sound sound;
    sound.loadMusic(NHACNEN_FILE);
    sound.loadChunk(NHACENDGAME_FILE);
    sound.playMusic();

    Sprite bird;
    bird.init(hehe.loadTexture(BIRD_SPRITE_FILE), BIRD_FRAMES, BIRD_CLIPS);

    ScrollingBackground background;
    background.setTexture(hehe.loadTexture(BACKGROUND_FILE));

    Monster monster;
    SDL_Texture *textureMonster = hehe.loadTexture(MONSTER_FILE);
    monster.setMonster(textureMonster);

    Move mouse;

    bool quit = false;
    SDL_Event e;
    deque<Monster> dq = {monster};
    deque<SDL_Rect> dpr;
    int time = SDL_GetTicks();
    while(!quit) {
        hehe.prepareScene(NULL);

        mouse.update();

        background.scroll(1);
        hehe.renderScrollingBackground(background);


        while(SDL_PollEvent(&e) != 0)
            if(e.type == SDL_QUIT)
                quit = true;

        const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);

        if(currentKeyStates[SDL_SCANCODE_UP]) mouse.turnNorth();
        if(currentKeyStates[SDL_SCANCODE_DOWN]) mouse.turnSouth();
        if(currentKeyStates[SDL_SCANCODE_LEFT]) mouse.turnWest();
        if(currentKeyStates[SDL_SCANCODE_RIGHT]) mouse.turnEast();

        bird.tick();
        SDL_Rect player = hehe.renderSprite(mouse.x, mouse.y, bird);
        mouse.move();

        for(int i = 0; i < dq.size(); i++) {
            SDL_Rect mst = hehe.renderMonster(dq[i]);
            if(isOverLap(player, mst)) {
                Mix_PauseMusic();
                sound.playChunk();
                SDL_Delay(1000);
                quit = true;
            }
            dq[i].moveMonster();
        }

        if(SDL_GetTicks() - time >= 1000) {
            time = SDL_GetTicks();
            Monster hihi;
            hihi.setMonster(textureMonster);
            dq.push_back(hihi);
        }

        if(dq[0].x <= -100)
            dq.pop_front();
        hehe.presentScene();

        SDL_Delay(10);
    }
    hehe.quit();
    return 0;
}
