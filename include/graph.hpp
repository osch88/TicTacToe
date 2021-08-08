#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"

class Graphic
{
public:
    
    Graphic(const char* title, const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT);
    SDL_Texture* loadTexture(const char* p_filePath);
    void cleanUp();                                     //Destroy window and renderer memory
    void clear();                                       //RenderClear
    void render(Entity& p_entity);
    void display();                                     //RenderPresent 
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};