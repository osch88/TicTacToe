#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <vector>

#include "graph.hpp"
#include "entity.hpp"
#include "math.hpp"

int main( int argc, char* args[] )
{

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	}

    if(!(IMG_Init(IMG_INIT_PNG)))
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }

    const int SCREEN_WIDTH  = 1280;
    const int SCREEN_HEIGHT =  720;

    Graphic window("Hello World!", SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Texture* grassTexture = window.loadTexture("res/grass.png");

    std::vector<Entity> entities = {    Entity( Vector2f(100 , 300) , grassTexture ),
                                        Entity( Vector2f(200 , 300) , grassTexture ),
                                        Entity( Vector2f(300 , 300) , grassTexture )
                                    };
    bool gameRunning = true;

    while( gameRunning )
    {
        SDL_Event e;
        if( SDL_PollEvent(&e) )
        {
            if( e.type == SDL_QUIT )
                gameRunning = false;
        }

        window.clear();

        for( Entity& e:entities )
        {
            window.render( e );
        }

        window.display();

    }

    //Closing down program
    window.cleanUp();
    IMG_Quit();
    SDL_Quit();

    return 0;
}