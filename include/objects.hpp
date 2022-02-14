#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Objects
{
public:
    Objects();

    SDL_Rect src;
    SDL_Rect dst;

    static const int OneSqr = 213;
    
    static SDL_Rect sqrNo1;
    static SDL_Rect sqrNo2;
    static SDL_Rect sqrNo3;
    static SDL_Rect sqrNo4;
    static SDL_Rect sqrNo5;
    static SDL_Rect sqrNo6;
    static SDL_Rect sqrNo7;
    static SDL_Rect sqrNo8;
    static SDL_Rect sqrNo9;

};