#include "defs.h"
#include "common.h"
#include "sprite.h"
#include "move.h"
#include "collision.h"
#include "sound.h"
#include "menu.h"

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
    Common common;
    common.init();
    TTF_Font* font = common.loadFont(FONT_FILE, 20);

    Sound sound;
    sound.loadMusic(NHACNEN_FILE);
    sound.loadChunk(NHACENDGAME_FILE);
    sound.playMusic();

    Sprite bird;
    bird.init(common.loadTexture(BIRD_SPRITE_FILE), BIRD_FRAMES, BIRD_CLIPS);

    Sprite ragnarok;
    ragnarok.init(common.loadTexture(RAGNAROK_SPRITE_FILE), RAGNAROK_FRAMES, RAGNAROK_CLIPS);

    ScrollingBackground background;
    background.setTexture(common.loadTexture(BACKGROUND_FILE));

    Monster monster;
    monster.setMonster(ragnarok.texture);

    Move mouse;

    Menu menu;

    bool quit = false;
    SDL_Event e;

    deque<Monster> dq = {monster};
    deque<SDL_Rect> dpr;

    int time = SDL_GetTicks();
    int cnt = 0;
    while(!quit) {
        common.prepareScene(NULL);

        mouse.update();

        background.scroll(1);
        common.renderScrollingBackground(background);

        while(SDL_PollEvent(&e) != 0)
            if(e.type == SDL_QUIT)
                quit = true;

        const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);

        if(currentKeyStates[SDL_SCANCODE_UP]) mouse.turnNorth();
        if(currentKeyStates[SDL_SCANCODE_DOWN]) mouse.turnSouth();
        if(currentKeyStates[SDL_SCANCODE_LEFT]) mouse.turnWest();
        if(currentKeyStates[SDL_SCANCODE_RIGHT]) mouse.turnEast();

        bird.tick();
        SDL_Rect player = common.renderSprite(mouse.x, mouse.y, bird);
        mouse.move();

        for(int i = 0; i < dq.size(); i++) {
            SDL_Rect mst = common.renderMonster(dq[i]);
            ragnarok.tick();
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
            hihi.setMonster(ragnarok.texture);
            dq.push_back(hihi);
        }

        if(dq[0].x <= -100) {
            dq.pop_front();
            cnt++;
        }

        menu.randColor();
        SDL_Color color = {menu.r, menu.g, menu.b, 255};
        string str = "SCORE: ";
        str += to_string(cnt);
        const char* s = str.c_str();
        SDL_Texture* score = common.fontTexture(s, font, color);
        common.renderTexture(score, 10, 10);

        common.presentScene();

        SDL_Delay(10);
    }
    common.quit();
    return 0;
}
