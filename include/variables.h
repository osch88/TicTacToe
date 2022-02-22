#pragma once
#include <SDL2/SDL.h>

// Window
constexpr int SCREEN_WIDTH = 900;
constexpr int SCREEN_HEIGHT = 900;

// Board
constexpr int N = 3;
constexpr int CELL_WIDTH = SCREEN_WIDTH / N;
constexpr int CELL_HEIGHT = SCREEN_HEIGHT / N;

// Color
SDL_Color base = {.r = 0, .g = 0, .b = 0, .a = 255};
SDL_Color bkgd = {.r = 124, .g = 218, .b = 254, .a = 255};
