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
//#define HERO_JUMP_ATTACK_FILE "img/gothic-hero-crouch-slash.png"

#define DEMON_FLY_FILE "img/demon-idle.png"
#define DEMON_ATTACK_FILE "img/demon-attack.png"

#define SKULL_FILE "img/fire-skull-no-fire.png"
#define FIRE_SKULL_FIRE "img/fire-skull.png"

#define BOSS_IDLE_FILE "img/ghost-idle.png"
#define BOSS_VANISH_FILE "img/ghost-vanish.png"
#define BOSS_SHRIEK_FILE "img/ghost-shriek.png"

#define NHACNEN_FILE "sound/nhac_play.mp3"
#define NHACMENU_FILE "sound/nhac_menu.mp3"

#define NHAC_BLEED_FILE "sound/bleed.wav"
#define NHAC_KILL_MONSTER_FILE "sound/nhac_kill_monster.wav"
#define NHACENDGAME_FILE "sound/nhac_endgame.wav"

#define FONT_FILE "text/text.ttf"

#define HIGHSCORE_FILE "highscore.txt"

const int SCREEN_WIDTH = 1536;
const int SCREEN_HEIGHT = 672;

const int SCROLL_BACKGROUND = 2;
const int SPEED_HERO = 5;
const int SPEED_MONSTER = 5;

const int BIG_FONT = 100;
const int SMALL_FONT = 30;

const int HP_HERO = 100;
const int HP_SKULL = 100;
const int HP_DEMON = 150;
const int HP_BOSS = 500;
