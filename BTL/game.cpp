#include "game.h"

SDL_Texture* Game::textureHeroRun = nullptr;
SDL_Texture* Game::textureHeroJumpAttack = nullptr;

SDL_Texture* Game::textureDemonFly = nullptr;
SDL_Texture* Game::textureDemonAttack = nullptr;

SDL_Texture* Game::mainMenu = nullptr;
bool Game::quit = false;
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

    delete demon;
    demon = nullptr;

    Mix_FreeMusic(soundtrack);
    soundtrack = nullptr;
    Mix_FreeMusic(menuMusic);
    menuMusic = nullptr;

    Mix_FreeChunk(endgame);
    endgame = nullptr;
    Mix_FreeChunk(killmonster);
    killmonster = nullptr;

    SDL_DestroyTexture(textureHeroRun);
    textureHeroRun = nullptr;
    SDL_DestroyTexture(textureHeroJumpAttack);
    textureHeroJumpAttack = nullptr;

    SDL_DestroyTexture(textureDemonFly);
    textureDemonFly = nullptr;
    SDL_DestroyTexture(textureDemonAttack);
    textureDemonAttack = nullptr;

    //delete common;
    //common = nullptr;

    //SDL_DestroyTexture();
    closeGame();
}

void Game::initGame()
{
    menuMusic = sound->loadMusic(NHACMENU_FILE);
    soundtrack = sound->loadMusic(NHACNEN_FILE);

    killmonster = sound->loadChunk(NHAC_KILL_MONSTER_FILE);
    endgame = sound->loadChunk(NHACENDGAME_FILE);

    background->setTexture(common->loadTexture(BACKGROUND_FILE));

    font = common -> loadFont(FONT_FILE, SMALL_FONT);

    textureHeroRun = Common::loadTexture(HERO_RUN_FILE);
    textureHeroJumpAttack = Common::loadTexture(HERO_JUMP_ATTACK_FILE);

    textureDemonFly = Common::loadTexture(DEMON_FLY_FILE);
    textureDemonAttack = Common::loadTexture(DEMON_ATTACK_FILE);

    mainMenu = Common::loadTexture(MAINMENU_FILE);
    gameover = Common::loadTexture(GAMEOVER_FILE);
}

void Game::playGame()
{
    sound->playMusic(soundtrack);

    hero->init(textureHeroRun, 12, 100);
    hero->initHero();

    demon->init(textureDemonFly, 6, 100);
    demon->initMonster(15);

    quit = false;
    SDL_Event e;

    Uint32 time = SDL_GetTicks();
    Uint32 time2 = 2000;

    distance = 0;
    SDL_Color color = {255, 255, 255, 0};
    string str = "YOUR SCORE: ";
    str += to_string(distance);
    const char* s = str.c_str();
    SDL_Texture* score = common->fontTexture(s, font, color);

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
        distance += SCROLL_BACKGROUND;

        hero->render();
        hero->update();
        hero->move();

        for (size_t i = 0; i < dq.size(); i++) {
            dq[i]->render();
            dq[i]->update();
            dq[i]->moveMonster();

            SDL_Rect r1 = {hero->dstRect.x, hero->dstRect.y, hero->dstRect.w - 60, hero->dstRect.h};
            SDL_Rect r2 = {dq[i]->dstRect.x + 110, dq[i]->dstRect.y, dq[i]->dstRect.w - 110, dq[i]->dstRect.h};
            if (Collision::isOverLap(r1, r2)) {
                if (hero->check && !demon->check) {
                common->renderTexture(gameover, SCREEN_WIDTH / 2 - 270, SCREEN_HEIGHT / 2 - 270);

                common->renderTexture(score, SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 270 + 350);

                common->presentScene();

                Mix_PauseMusic();
                sound->playChunk(endgame);
                SDL_Delay(3000);
                quit = true;
                }
                else {
                    sound->playChunk(killmonster);
                    dq.pop_front();
                }
            }

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
        str = "YOUR SCORE: ";
        str += to_string(distance);
        const char* s = str.c_str();
        score = common->fontTexture(s, font, color);
        common->renderTexture(score, 10, 10);

        common->presentScene();
    }
}

void Game::renderMenu()
{
    SDL_Event e;
    int x, y;
    while (true) {
        Common::renderTexture(mainMenu, SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2 - 250);
        Common::presentScene();
        while (SDL_PollEvent(&e)) {
            SDL_GetMouseState(&x, &y);
            if (e.type == SDL_MOUSEBUTTONDOWN && x > 715 && x < 833) {
                if (y > 277 && y < 305 ) return;
                if (y > 423 && y < 455) {
                    quit = true;
                    return;
                }
            }
        }
    }
}

void Game::closeGame()
{
    common -> quit();
}
