#pragma once

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
using namespace std;

#define WINDOW_TITLE "Game cua Huy"
#define BIRD_SPRITE_FILE "img/bird_sprite.png"
#define RAGNAROK_SPRITE_FILE "img/ragnarok_sprite.png"
#define BACKGROUND_FILE "img/forest.jpg"
#define MONSTER_FILE "img/Du_long.png"
#define NHACNEN_FILE "sound/nhac_nen.mp3"
#define NHACENDGAME_FILE "sound/nhac_endgame3.wav"
#define FONT_FILE "text/text.ttf"
#define SCROLL_BACKGROUND 2
#define SPEED_BIRD 5
#define SPEED_MONSTER 5

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 540;

const int BIRD_CLIPS[][4] = {
    {0, 0, 90, 90},
    {91, 0, 90, 90},
    {182, 0, 90, 90},
    {273, 0, 90, 90},
    {364, 0, 90, 90},

    {0, 80, 90, 90},
    {91, 80, 90, 90},
    {182, 80, 90, 90},
    {273, 80, 90, 90},
    {364, 80, 90, 90},

    {0, 170, 90, 90},
    {91, 170, 90, 90},
    {182, 170, 90, 90},
    {273, 170, 90, 90},
};
const int BIRD_FRAMES = sizeof(BIRD_CLIPS) / sizeof(int) / 4;

const int RAGNAROK_CLIPS[][4] = {
    {3, 5, 63, 63}, {3, 5, 63, 63},
    {65, 5, 63, 63}, {65, 5, 63, 63},
    {127, 5, 63, 63}, {127, 5, 63, 63},
    {206, -7, 63, 63}, {206, -7, 63, 63},
    {270, -7, 63, 63}, {270, -7, 63, 63},
    {336, -7, 63, 63}, {336, -7, 63, 63},
    {401, -7, 63, 63}, {401, -7, 63, 63},
    {454, 5, 63, 63}, {454, 5, 63, 63},
};
const int RAGNAROK_FRAMES = sizeof(RAGNAROK_CLIPS) / sizeof(int) / 4;
