#include "objects.hpp"

Objects::Objects()
{
    src.x = src.y = src.w = src.h = 0;
    dst.x = dst.y = 0;
    dst.w = dst.h = 640;
}

SDL_Rect Objects::sqrNo1 = {0, 0, OneSqr, OneSqr};
SDL_Rect Objects::sqrNo2 = {OneSqr, 0, OneSqr, OneSqr};
SDL_Rect Objects::sqrNo3 = {OneSqr * 2, 0, OneSqr, OneSqr};

SDL_Rect Objects::sqrNo4 = {0, OneSqr, OneSqr, OneSqr};
SDL_Rect Objects::sqrNo5 = {OneSqr, OneSqr, OneSqr, OneSqr};
SDL_Rect Objects::sqrNo6 = {OneSqr * 2, OneSqr, OneSqr, OneSqr};

SDL_Rect Objects::sqrNo7 = {0, OneSqr*2, OneSqr, OneSqr};
SDL_Rect Objects::sqrNo8 = {OneSqr, OneSqr*2, OneSqr, OneSqr};
SDL_Rect Objects::sqrNo9 = {OneSqr * 2, OneSqr*2, OneSqr, OneSqr};