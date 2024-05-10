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
    {0, 0, 182, 168},
    {181, 0, 182, 168},
    {364, 0, 182, 168},
    {547, 0, 182, 168},
    {728, 0, 182, 168},

    {0, 170, 182, 168},
    {181, 170, 182, 168},
    {364, 170, 182, 168},
    {547, 170, 182, 168},
    {728, 170, 182, 168},

    {0, 340, 182, 168},
    {181, 340, 182, 168},
    {364, 340, 182, 168},
    {547, 340, 182, 168},
};
const int BIRD_FRAMES = sizeof(BIRD_CLIPS) / sizeof(int) / 4;

const int RAGNAROK_CLIPS[][4] = {
    {10, 8, 121, 154}, {10, 8, 121, 154},
    {134, 8, 121, 154}, {134, 8, 121, 154},
    {258, 8, 121, 154}, {258, 8, 121, 154},
    {416, 0, 121, 154}, {416, 0, 121, 154},
    {544, 0, 121, 154}, {544, 0, 121, 154},
    {676, 0, 121, 154}, {676, 0, 121, 154},
    {807, 0, 121, 154}, {807, 0, 121, 154},
    {913, 8, 121, 154}, {913, 8, 121, 154},
};
const int RAGNAROK_FRAMES = sizeof(RAGNAROK_CLIPS) / sizeof(int) / 4;
