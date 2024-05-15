#include "game.h"

Game::Game()
{
    common = new Common();

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

    //delete common;
    //common = nullptr;

    //SDL_DestroyTexture();
    closeGame();
}

void Game::initGame()
{
    common->init();

    background->setTexture(common->loadTexture(BACKGROUND_FILE));

    sound->loadMusic(NHACNEN_FILE);
    sound->loadChunk(NHACENDGAME_FILE);

    font = common -> loadFont(FONT_FILE, 20);

    hero = new Move();
    hero->init();
}

void Game::playGame()
{
    sound -> playMusic();

    bool quit = false;
    SDL_Event e;

    while(!quit) {
        while (SDL_PollEvent(&e) != 0)
            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
                quit = true;

        common->prepareScene(nullptr);

        background->scroll(SCROLL_BACKGROUND);
        common->renderScrollingBackground(*background);

        hero->render();
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s", SDL_GetError());
        hero->update();
        hero->handleEvent();
        hero->move();


        common->presentScene();
        /*
        for (size_t i = 0; i < dq.size(); i++)
        {
            dq[i]->Update();

            if (SDL_HasIntersection(&birdRect, dq[i]->getRect()))
            {
                Mix_PauseMusic();
                sound -> playChunk();
                SDL_Delay(500);
                quit = true;
                std::cerr << "Ows ows.\n";
            }

            dq[i]->Render();
        }

        if (SDL_GetTicks() - time >= time2) {
            time = SDL_GetTicks();
            dq.push_back(new Sprite(HERO_RUN_FILE, 12, 100));
        }

        if (dq[0]->getRect()->x <= -100) {
            dq.pop_front();
            cnt++;
            time2--;
        }

//        menu.randColor();
//        SDL_Color color = {menu.r, menu.g, menu.b, 0};
//        string str = "SCORE: ";
//        str += to_string(cnt);
//        const char* s = str.c_str();
//        SDL_Texture* score = common.fontTexture(s, font, color);
//        common.renderTexture(score, 10, 10);

        common -> presentScene();

        SDL_Delay(20);*/
    }
}

void Game::closeGame()
{
    common -> quit();
}
