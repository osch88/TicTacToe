#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "graph.hpp"
#include "entity.hpp"

Graphic::Graphic(const char* title, const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT)
    :window(nullptr), renderer(nullptr)
{
    window = SDL_CreateWindow( title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == nullptr )
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( renderer == nullptr )
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
}

SDL_Texture* Graphic::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == nullptr)
        printf( "Failed to load texture! SDL Error: %s\n", SDL_GetError() );
        
	return texture;
}

void Graphic::cleanUp()
{
    SDL_DestroyWindow( window) ;
    SDL_DestroyRenderer(renderer);
}

void Graphic::clear()
{
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );
}

void Graphic::render( Entity& p_entity )
{
    SDL_Rect srcrect = {
        p_entity.getCurrentFrame().x,
        p_entity.getCurrentFrame().y,
        p_entity.getCurrentFrame().w,
        p_entity.getCurrentFrame().h
    };
    SDL_Rect dstrect = {
        p_entity.getPos().x,
        p_entity.getPos().y,
        p_entity.getCurrentFrame().w,
        p_entity.getCurrentFrame().h
    };

    SDL_RenderCopy( renderer, p_entity.getTexture(), &srcrect, &dstrect );
}

void Graphic::display()
{
    SDL_RenderPresent( renderer );
}