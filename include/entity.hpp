#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "math.hpp"

class Entity
{
public:
    Entity( Vector2f p_pos, SDL_Texture* p_tex );
    Vector2f& getPos()
    {
        return pos;
    }
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
private:
    Vector2f pos;
    SDL_Texture* texture;
    SDL_Rect currentFrame;
};