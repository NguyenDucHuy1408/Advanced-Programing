#include "game.h"

SDL_Texture* Game::textureHeroRun = nullptr;
SDL_Texture* Game::textureHeroJumpAttack = nullptr;

SDL_Texture* Game::textureDemonFly = nullptr;
SDL_Texture* Game::textureDemonAttack = nullptr;

SDL_Texture* Game::textureSkull = nullptr;
SDL_Texture* Game::textureFireSkull = nullptr;

SDL_Texture* Game::mainMenu = nullptr;

Sound* Game::sound = nullptr;

Mix_Music* Game::soundtrack = nullptr;
Mix_Music* Game::menuMusic = nullptr;

Mix_Chunk* Game::bleed = nullptr;
Mix_Chunk* Game::killmonster = nullptr;
Mix_Chunk* Game::endgame = nullptr;

bool Game::quit = false;
bool Game::checkSound = true;

Game::Game()
{
    common = new Common();

    hero = new Move();

    monster = new Monster();

    boss = new Boss();

    background = new ScrollingBackground();

    sound = new Sound();

    save = new Save();
}

Game::~Game()
{
    delete hero;
    hero = nullptr;

    delete background;
    background = nullptr;

    delete sound;
    sound = nullptr;

    delete monster;
    monster = nullptr;

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

    SDL_DestroyTexture(textureSkull);
    textureSkull = nullptr;
    SDL_DestroyTexture(textureFireSkull);
    textureFireSkull = nullptr;

    //delete common;
    //common = nullptr;

    //SDL_DestroyTexture();
    closeGame();
}

void Game::initGame()
{
    menuMusic = sound->loadMusic(NHACMENU_FILE);
    soundtrack = sound->loadMusic(NHACNEN_FILE);

    bleed = sound->loadChunk(NHAC_BLEED_FILE);
    killmonster = sound->loadChunk(NHAC_KILL_MONSTER_FILE);
    endgame = sound->loadChunk(NHACENDGAME_FILE);

    background->setTexture(common->loadTexture(BACKGROUND_FILE));

    font = common->loadFont(FONT_FILE, SMALL_FONT);
    bigFont = common->loadFont(FONT_FILE, BIG_FONT);

    textureHeroRun = Common::loadTexture(HERO_RUN_FILE);
    textureHeroJumpAttack = Common::loadTexture(HERO_JUMP_ATTACK_FILE);

    textureDemonFly = Common::loadTexture(DEMON_FLY_FILE);
    textureDemonAttack = Common::loadTexture(DEMON_ATTACK_FILE);

    textureSkull = Common::loadTexture(SKULL_FILE);
    textureFireSkull = Common::loadTexture(FIRE_SKULL_FIRE);

    mainMenu = Common::loadTexture(MAINMENU_FILE);
    gameover = Common::loadTexture(GAMEOVER_FILE);
}

void Game::playGame()
{
    if (checkSound)
        sound->playMusic(soundtrack);

    hero->init(textureHeroRun, 12, 100, 0);
    hero->initHero();

    if (monster->state == 0)
        monster->init(textureDemonFly, 6, 100, 0);
    else if (monster->state == 1)
        monster->init(textureSkull, 4, 100, 50);

    monster->initMonster();

    quit = false;
    SDL_Event e;

    Uint32 time = SDL_GetTicks();
    Uint32 time2 = 1500;

    distance = 0;
    highscore = save->readFile();

    SDL_Color color = {255, 255, 255, 0};

    string str = "YOUR SCORE: ";
    str += to_string(distance);
    const char* s = str.c_str();
    SDL_Texture* score = common->fontTexture(s, font, color);

    int cnt = 0;

    deque<Monster*> dq = {monster};

    boss->initBoss();
    int hpBoss = HP_BOSS;

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

        healthBar(hero->dstRect.x, hero->dstRect.y, 132, 10, HP_HERO, boss->hpHero, 0, 255, 0);
        hero->render();
        hero->update();
        hero->move();

        str = "YOUR SCORE: ";
        str += to_string(distance);
        const char* s = str.c_str();
        score = common->fontTexture(s, font, color);
        common->renderTexture(score, 10, 10);

        for (size_t i = 0; i < dq.size(); i++) {
            healthBar(dq[i]->dstRect.x, dq[i]->dstRect.y, dq[i]->dstRect.w, 10, dq[i]->hpMonster, dq[i]->currentHpMonster, 255, 0, 0);
            dq[i]->render();
            dq[i]->update();
            dq[i]->moveMonster();

            SDL_Rect r1 = {hero->dstRect.x, hero->dstRect.y, hero->dstRect.w - 60, hero->dstRect.h};
            SDL_Rect r2;
            if (dq[i]->state == 0)
                r2 = {dq[i]->dstRect.x + 110, dq[i]->dstRect.y, dq[i]->dstRect.w - 110, dq[i]->dstRect.h};
            else if (dq[i]->state == 1)
                r2 = {dq[i]->dstRect.x, dq[i]->dstRect.y, dq[i]->dstRect.w, dq[i]->dstRect.h};
            if (Collision::isOverLap(r1, r2)) {
                if (hero->check && !dq[i]->check) {
                    if (boss->hpHero <= 0) {
                        highscore = max (highscore, distance);
                        save->writeFile(highscore);
                        string str2 = "HIGHSCORE: ";
                        str2 += to_string(highscore);
                        const char* s2 = str2.c_str();
                        SDL_Texture* highscore_tex = common->fontTexture(s2, font, color);

                        common->renderTexture(gameover, SCREEN_WIDTH / 2 - 270, SCREEN_HEIGHT / 2 - 270);

                        common->renderTexture(score, SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 270 + 350);

                        common->renderTexture(highscore_tex, SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2 - 270 + 450);

                        common->presentScene();

                        Mix_PauseMusic();
                        if (checkSound)
                            sound->playChunk(endgame);
                        SDL_Delay(3000);
                        quit = true;
                    }
                    else {
                        if (checkSound)
                            sound->playChunk(bleed);
                        dq.pop_front();
                        i--;
                        boss->hpHero -= 20;
                        //cout << "mat mau\n";
                    }
                }
                else {
                    if (dq[i]->currentHpMonster <= 0) {
                        if (checkSound)
                            sound->playChunk(killmonster);
                        dq.pop_front();
                        i--;
                    }
                    else dq[i]->currentHpMonster -= 10;
                }
            }

            if (hero->srcRect.x == hero->w && !hero->check) {
                hero->check = true;
                hero->init(textureHeroRun, 12, 100, 0);
            }
            if (dq[i]->state == 0) {
                if (dq[i]->checkDistance(hero->dstRect) && dq[i]->check) {
                    dq[i]->check = false;
                    dq[i]->init(textureDemonAttack, 11, 100, 0);
                }
                if (dq[i]->srcRect.x == dq[i]->w && !dq[i]->check) {
                    dq[i]->check = true;
                    dq[i]->init(textureDemonFly, 6, 100, 0);
                }
            }
            else if (dq[i]->state == 1) {
                if (dq[i]->checkDistance(hero->dstRect) && dq[i]->check) {
                    dq[i]->check = false;
                    dq[i]->init(textureFireSkull, 8, 100, 50);
                }
                if (dq[i]->srcRect.x == dq[i]->w && !dq[i]->check) {
                    dq[i]->check = true;
                    dq[i]->init(textureSkull, 4, 100, 50);
                }
            }
        }

        if (SDL_GetTicks() - time >= time2 && cnt <= 10) {
            time = SDL_GetTicks();
            Monster* hihi = new Monster();
            if (hihi->state == 0)
                hihi->init(textureDemonFly, 6, 100, 0);
            else if (hihi->state == 1)
                hihi->init(textureSkull, 4, 100, 50);
            dq.push_back(hihi);
            cnt++;
        }

        if (cnt > 10) {
            boss->moveBoss(hero->dstRect);
            if (boss->STATE != BOSS_STATE::SHRIEK) {
                healthBar(boss->dstRect.x, boss->dstRect.y, boss->dstRect.w, 10, HP_BOSS, hpBoss, 255, 0, 0);
                boss->render();
                boss->update();
            }
            SDL_Rect r1 = {hero->dstRect.x, hero->dstRect.y, hero->dstRect.w - 60, hero->dstRect.h};
            SDL_Rect r2 = {boss->dstRect.x, boss->dstRect.y, boss->dstRect.w, boss->dstRect.h};
            if (Collision::isOverLap(r1, r2)) {
                if (hero->check) {
                    if (boss->hpHero <= 0) {
                        highscore = max (highscore, distance);
                        save->writeFile(highscore);
                        string str2 = "HIGHSCORE: ";
                        str2 += to_string(highscore);
                        const char* s2 = str2.c_str();
                        SDL_Texture* highscore_tex = common->fontTexture(s2, font, color);

                        common->renderTexture(gameover, SCREEN_WIDTH / 2 - 270, SCREEN_HEIGHT / 2 - 270);

                        common->renderTexture(score, SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 270 + 350);

                        common->renderTexture(highscore_tex, SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2 - 270 + 450);

                        common->presentScene();

                        Mix_PauseMusic();
                        if (checkSound)
                            sound->playChunk(endgame);
                        SDL_Delay(3000);
                        quit = true;
                    }
                }
                else {
                    if (hpBoss <= 0) {
                        if (checkSound)
                            sound->playChunk(killmonster);
                        const char* s = "VICTORY";
                        SDL_Texture* victory = common->fontTexture(s, bigFont, color);
                        common->renderTexture(victory, SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 - 50);
                        common->presentScene();
                        SDL_Delay(3000);
                        quit = true;
                    }
                    else {
                        hpBoss -= 1;
                    }
                }
            }
            if (hero->srcRect.x == hero->w && !hero->check) {
                hero->check = true;
                hero->init(textureHeroRun, 12, 100, 0);
            }
        }

        distance += SCROLL_BACKGROUND;

        common->presentScene();
    }
}

void Game::healthBar(int x, int y, int w, int h, int maxHealth, int currentHealth, int r, int g, int b)
{
    SDL_SetRenderDrawColor(Common::renderer, 128, 128, 128, 255);
    SDL_Rect bgRect = {x, y, w, h};
    SDL_RenderDrawRect(Common::renderer, &bgRect);

    int healthWidth = (int)(currentHealth * w / (float)maxHealth);

    SDL_SetRenderDrawColor(Common::renderer, r, g, b, 255);
    SDL_Rect health = {x, y, healthWidth, h};
    SDL_RenderFillRect(Common::renderer, &health);
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

                if (y > 350 && y < 385) {
                    if (checkSound) {
                        Mix_PauseMusic();
                        checkSound = false;
                    }
                    else {
                        sound->playMusic(soundtrack);
                        checkSound = true;
                    }
                }
            }
        }
    }
}

void Game::closeGame()
{
    common -> quit();
}
