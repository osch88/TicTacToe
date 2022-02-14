#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <vector>

#include "graph.hpp"
#include "objects.hpp"

class Wrapper {
    private:
        SDL_Renderer* gRenderer = NULL;
        const int SCREEN_WIDTH  = 640;
        const int SCREEN_HEIGHT = 640;
    
    public:
        void run();
        Wrapper() = default;
        ~Wrapper();
};
