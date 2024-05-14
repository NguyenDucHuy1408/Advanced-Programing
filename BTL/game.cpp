#include "game.h"

Game::Game()
{
    common = new Common();

    background = new ScrollingBackground();

    sound = new Sound();

    bird = new Sprite();

    mouse = new Move();

    ragnarokTexture = NULL;

    font = NULL;
}

Game::~Game()
{
    delete common;
    delete background;
    delete sound;
    delete bird;
    delete mouse;

    SDL_DestroyTexture(ragnarokTexture);
    closeGame();
}

void Game::initGame()
{
    common -> init();

    background -> setTexture(common -> loadTexture(BACKGROUND_FILE));

    sound -> loadMusic(NHACNEN_FILE);
    sound -> loadChunk(NHACENDGAME_FILE);

    bird -> init(common -> loadTexture(BIRD_SPRITE_FILE),
              BIRD_FRAMES, BIRD_CLIPS);

    ragnarokTexture = common -> loadTexture(RAGNAROK_SPRITE_FILE);
    ragnarok.init(ragnarokTexture,
                  RAGNAROK_FRAMES, RAGNAROK_CLIPS);

    font = common -> loadFont(FONT_FILE, 20);
}

void Game::playGame()
{
    sound -> playMusic();

    bool quit = false;
    SDL_Event e;

    deque<Sprite> dq = {ragnarok};
    deque<SDL_Rect> dpr;

    int time = SDL_GetTicks();
    int cnt = 0;
    int time2 = 500;
    while(!quit) {
        common -> prepareScene(NULL);

        mouse -> update();

        background -> scroll(SCROLL_BACKGROUND);
        common -> renderScrollingBackground(*background);

        while (SDL_PollEvent(&e) != 0)
            if (e.type == SDL_QUIT)
                quit = true;

        mouse -> checkEvent();

        bird -> tick();
        SDL_Rect birdRect = common -> renderSprite(mouse -> x, mouse -> y, *bird);
        SDL_Rect player = {birdRect.x + 30, birdRect.y + 30, 40, 40};
        mouse -> move();

        for (size_t i = 0; i < dq.size(); i++) {
            SDL_Rect mst = common -> renderSprite(dq[i].x, dq[i].y, dq[i]);
            SDL_Rect mst2 = {mst.x + 10, mst.y + 28, 40, 35};
            //
            dq[i].tick();
            if (Collision::isOverLap(player, mst2)) {
                Mix_PauseMusic();
                sound -> playChunk();
                SDL_Delay(500);
                quit = true;
            }
            dq[i].moveMonster();
        }

        if (SDL_GetTicks() - time >= time2) {
            time = SDL_GetTicks();
            Sprite hihi;
            hihi.init(ragnarokTexture, RAGNAROK_FRAMES, RAGNAROK_CLIPS);
            dq.push_back(hihi);
        }

        if (dq[0].x <= -100) {
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

        SDL_Delay(20);
    }
}

void Game::closeGame()
{
    common -> quit();
}
