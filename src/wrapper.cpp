#include "wrapper.hpp"

void Wrapper::run(){
 if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	}

    if(!(IMG_Init(IMG_INIT_PNG))) {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }

    Graphic window("Tic Toc Toe", SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Texture* backTexture = window.loadTexture("res/gridTrans.png");
    SDL_Texture* marksTexture = window.loadTexture("res/marks.png");

    window.clear();

    Objects base;
    base.src = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    Objects cross;
    cross.src = {0, 0, 160, 160};

    Objects circle;
    circle.src = {160, 0, 160, 160};

    window.render( base.src, base.dst, backTexture );

    window.render( circle.src, Objects::sqrNo1, marksTexture );
    window.render( circle.src, Objects::sqrNo2, marksTexture );
    window.render( circle.src, Objects::sqrNo3, marksTexture );

    window.render( cross.src, Objects::sqrNo4, marksTexture );
    window.render( cross.src, Objects::sqrNo5, marksTexture );
    window.render( cross.src, Objects::sqrNo6, marksTexture );
    
    window.render( circle.src, Objects::sqrNo7, marksTexture );
    window.render( circle.src, Objects::sqrNo8, marksTexture );
    window.render( circle.src, Objects::sqrNo9, marksTexture );

    // Förbättring: en class som identifierar musknapp koord. Skickar in till en annan klass och tillbaka kommer SDL_Rect

    window.display();


    bool gameRunning = true;

    while( gameRunning ) {
        SDL_Event e;
        if( SDL_PollEvent(&e) ) {
            if( e.type == SDL_QUIT )
                gameRunning = false;
        }
    }
    window.cleanUp();
}

Wrapper::~Wrapper() {
    IMG_Quit();
    SDL_Quit();
}