#include "game.h"

SDL_Texture* Game::textureHeroRun = nullptr;
SDL_Texture* Game::textureHeroJumpAttack = nullptr;

SDL_Texture* Game::textureDemonFly = nullptr;
SDL_Texture* Game::textureDemonAttack = nullptr;


Game::Game()
{
    common = new Common();

    hero = new Move();

    demon = new Monster();

    background = new ScrollingBackground();

    sound = new Sound();
}

Game::~Game()
{
    delete hero;
    hero = nullptr;

    delete background;
    background = nullptr;

    delete sound;
    sound = nullptr;

    Mix_FreeMusic(soundtrack);
    soundtrack = nullptr;
    Mix_FreeMusic(menuMusic);
    menuMusic = nullptr;

    Mix_FreeChunk(chunk);
    chunk = nullptr;

    //delete common;
    //common = nullptr;

    //SDL_DestroyTexture();
    closeGame();
}

void Game::initGame()
{
    menuMusic = sound->loadMusic(NHACMENU_FILE);
    soundtrack = sound->loadMusic(NHACNEN_FILE);
    chunk = sound->loadChunk(NHACENDGAME_FILE);

    background->setTexture(common->loadTexture(BACKGROUND_FILE));

    font = common -> loadFont(FONT_FILE, 20);

    textureHeroRun = Common::loadTexture(HERO_RUN_FILE);
    textureHeroJumpAttack = Common::loadTexture(HERO_JUMP_ATTACK_FILE);

    textureDemonFly = Common::loadTexture(DEMON_FLY_FILE);
    textureDemonAttack = Common::loadTexture(DEMON_ATTACK_FILE);

    hero->init(textureHeroRun, 12, 100);
    hero->initHero();

    demon->init(textureDemonFly, 6, 100);
    demon->initMonster(15);
}

void Game::playGame()
{
    sound->playMusic(soundtrack);

    bool quit = false;
    SDL_Event e;

    Uint32 time = SDL_GetTicks();
    Uint32 time2 = 2000;
    deque<Monster*> dq = {demon};
    while(!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
                Mix_PauseMusic();
                sound->playMusic(menuMusic);
            }
            hero->handleEvent(e);
        }

        common->prepareScene(nullptr);

        background->scroll(SCROLL_BACKGROUND);
        common->renderScrollingBackground(*background);

        hero->render();
        hero->update();
        hero->move();

        for (size_t i = 0; i < dq.size(); i++) {
            dq[i]->render();
            dq[i]->update();
            dq[i]->moveMonster();

            //SDL_Rect
            /*if (SDL_HasIntersection(&hero->dstRect, &dq[i]->dstRect)) {
                Mix_PauseMusic();
                sound->playChunk(chunk);
                SDL_Delay(1000);
                quit = true;
            }*/

            if (hero->srcRect.x == hero->w && !hero->check) {
                hero->check = true;
                hero->init(textureHeroRun, 12, 100);
            }
            if (dq[i]->checkDistance(hero->dstRect) && dq[i]->check) {
                dq[i]->check = false;
                dq[i]->init(textureDemonAttack, 11, 100);
            }
            if (dq[i]->srcRect.x == dq[i]->w && !dq[i]->check) {
                dq[i]->check = true;
                dq[i]->init(textureDemonFly, 6, 100);
            }
        }

        if (SDL_GetTicks() - time >= time2) {
            time = SDL_GetTicks();
            Monster* hihi = new Monster();
            hihi->init(textureDemonFly, 6, 100);
            hihi->initMonster(15);
            dq.push_back(hihi);
        }

        if (dq[0]->dstRect.x <= -150) {
            dq.pop_front();
            time2--;
        }

        common->presentScene();

//        menu.randColor();
//        SDL_Color color = {menu.r, menu.g, menu.b, 0};
//        string str = "SCORE: ";
//        str += to_string(cnt);
//        const char* s = str.c_str();
//        SDL_Texture* score = common.fontTexture(s, font, color);
//        common.renderTexture(score, 10, 10);
    }
}

void Game::closeGame()
{
    common -> quit();
}
