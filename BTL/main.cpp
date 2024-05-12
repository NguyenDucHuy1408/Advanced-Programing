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

    SDL_Texture* ragnarokTexture = common.loadTexture(RAGNAROK_SPRITE_FILE);
    Sprite ragnarok;
    ragnarok.init(ragnarokTexture, RAGNAROK_FRAMES, RAGNAROK_CLIPS);

    ScrollingBackground background;
    background.setTexture(common.loadTexture(BACKGROUND_FILE));

    Move mouse;

    Menu menu;

    bool quit = false;
    SDL_Event e;

    deque<Sprite> dq = {ragnarok};
    deque<SDL_Rect> dpr;

    int time = SDL_GetTicks();
    int cnt = 0;
    int time2 = 500;
    while(!quit) {
        common.prepareScene(NULL);

        mouse.update();

        background.scroll(SCROLL_BACKGROUND);
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
        SDL_Rect birdRect = common.renderSprite(mouse.x, mouse.y, bird);
        SDL_Rect player = {birdRect.x + 30, birdRect.y + 30, 40, 40};
        mouse.move();

        for(int i = 0; i < dq.size(); i++) {
            SDL_Rect mst = common.renderSprite(dq[i].x, dq[i].y, dq[i]);
            SDL_Rect mst2 = {mst.x + 10, mst.y + 28, 40, 35};
            //
            dq[i].tick();
            if(isOverLap(player, mst2)) {
                Mix_PauseMusic();
                sound.playChunk();
                SDL_Delay(500);
                quit = true;
            }
            dq[i].moveMonster();
        }

        if(SDL_GetTicks() - time >= time2) {
            time = SDL_GetTicks();
            Sprite hihi;
            hihi.init(ragnarokTexture, RAGNAROK_FRAMES, RAGNAROK_CLIPS);
            dq.push_back(hihi);
        }

        if(dq[0].x <= -100) {
            dq.pop_front();
            cnt++;
            time2--;
        }

        menu.randColor();
        SDL_Color color = {menu.r, menu.g, menu.b, 0};
        string str = "SCORE: ";
        str += to_string(cnt);
        const char* s = str.c_str();
        SDL_Texture* score = common.fontTexture(s, font, color);
        common.renderTexture(score, 10, 10);

        common.presentScene();

        SDL_Delay(20);
    }
    SDL_DestroyTexture(ragnarokTexture);
    ragnarokTexture == NULL;

    common.quit();
    return 0;
}
