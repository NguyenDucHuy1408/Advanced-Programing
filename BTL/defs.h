#pragma once

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
using namespace std;

#define WINDOW_TITLE "HUY'S ADVENTURE"

#define MENU_FILE "img/menu.png"
#define MAINMENU_FILE "img/main_menu.png"
#define BACKGROUND_FILE "img/bg.png"
#define GAMEOVER_FILE "img/gameover.png"

#define HERO_RUN_FILE "img/gothic-hero-run.png"
#define HERO_JUMP_ATTACK_FILE "img/gothic-hero-jump-attack.png"

#define DEMON_FLY_FILE "img/demon-idle.png"
#define DEMON_ATTACK_FILE "img/demon-attack.png"

#define NHACNEN_FILE "sound/nhac_play.mp3"
#define NHACMENU_FILE "sound/nhac_menu.mp3"

#define NHAC_KILL_MONSTER_FILE "sound/nhac_kill_monster.wav"
#define NHACENDGAME_FILE "sound/nhac_endgame3.wav"

#define FONT_FILE "text/text.ttf"

const int SCREEN_WIDTH = 1536;
const int SCREEN_HEIGHT = 672;

const int SCROLL_BACKGROUND = 2;
const int SPEED_HERO = 5;
const int SPEED_MONSTER = 5;

const int BIG_FONT = 50;
const int SMALL_FONT = 30;
