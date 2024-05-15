#pragma once

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
using namespace std;

#define WINDOW_TITLE "Game cua Huy"

#define MENU_FILE "img/menu.png"
#define BACKGROUND_FILE "img/bg.png"

#define HERO_RUN_FILE "img/hero_run.png"

#define NHACNEN_FILE "sound/nhac_nen.mp3"
#define NHACENDGAME_FILE "sound/nhac_endgame3.wav"

#define FONT_FILE "text/text.ttf"

const int SCREEN_WIDTH = 1536;
const int SCREEN_HEIGHT = 672;

const int SCROLL_BACKGROUND = 3;
const int SPEED_HERO = 8;
const int SPEED_MONSTER = 8;
