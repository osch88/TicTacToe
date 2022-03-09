#include "engine.h"
#include "variables.h"
#include "game.h"

Engine *Engine::s_Instance = nullptr;
Game game;

bool Engine::Init()
{
    // Init SDL
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted = IMG_Init(flags);

    if (SDL_Init(SDL_INIT_VIDEO) != 0 || initted & flags != flags)
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    if (TTF_Init() != 0)
    {
        SDL_Log("Failed to initialize TTF: %s", SDL_GetError());
        return false;
    }

    // Create Window
    m_Window = SDL_CreateWindow("TicTocToe",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                SCREEN_WIDTH, SCREEN_HEIGHT,
                                0);

    if (m_Window == nullptr)
    {
        SDL_Log("Failed to create Window: %s", SDL_GetError());
        return false;
    }

    // Create Renderer
    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (m_Renderer == nullptr)
    {
        SDL_Log("Failed to create Renderer: %s", SDL_GetError());
        return false;
    }

    // Load texture

    return m_IsRunning = true;
}

void Engine::Events()
{
    // Handle events on queue
    while (SDL_PollEvent(&m_Event) != 0)
    {
        if (m_Event.type == SDL_QUIT || m_Event.key.keysym.sym == SDLK_q)
        {
            Quit();
        }
        if (m_Event.type == SDL_MOUSEBUTTONDOWN && m_GameOver == false)
        {
            SDL_GetMouseState(&m_MousePos.x, &m_MousePos.y);
            game.UpdateBoard(m_MousePos);
        }
        if (m_Event.key.keysym.sym == SDLK_r)
        {
            SDL_Log("Reset pressed");
            game.resetBoard();
            m_GameOver = false;
        }
    }
}

void Engine::Update()
{
    // Check if we have a winner
    if (game.Solution() > 0 && m_GameOver == false)
    {
        std::cout << "Player " << game.Solution() << " has won!" << std::endl;
        m_GameOver = true;
        m_OutputText = "We have a winner";
    }
    else if (game.Solution() == -1 && m_GameOver == false)
    {
        std::cout << "DRAW!" << std::endl;
        m_GameOver = true;
        m_OutputText = "DRAW";
    }
}

void Engine::Render()
{
    // Render background
    SDL_SetRenderDrawColor(m_Renderer, bkgd.r, bkgd.g, bkgd.b, bkgd.a);
    SDL_RenderClear(m_Renderer);

    // SDL_RenderDrawRects
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (game.getPlayer(row, col) == STATE::PLAYER1)
            {
                SDL_SetRenderDrawColor(m_Renderer, 0, 0, 255, 255);
                SDL_RenderFillRect(m_Renderer, game.getRect(row, col));
            }
            if (game.getPlayer(row, col) == STATE::PLAYER2)
            {
                SDL_SetRenderDrawColor(m_Renderer, 0, 255, 0, 255);
                SDL_RenderFillRect(m_Renderer, game.getRect(row, col));
            }
        }
    }

    // Render board
    SDL_SetRenderDrawColor(m_Renderer, base.r, base.g, base.b, base.a);
    for (size_t i = 1; i < 3; i++)
    {
        SDL_RenderDrawLine(m_Renderer, CELL_WIDTH * i, 0, CELL_WIDTH * i, SCREEN_HEIGHT);
        SDL_RenderDrawLine(m_Renderer, 0, CELL_HEIGHT * i, SCREEN_WIDTH, CELL_HEIGHT * i);
    }

    // Font
    if (m_GameOver)
    {
        TTF_Font *Sans = TTF_OpenFont("assets/font/Teko-Bold.ttf", 24);
        SDL_Color White = {255, 255, 255};

        m_SurfaceMessage = TTF_RenderText_Solid(Sans, m_OutputText.c_str(), White);
        m_Message = SDL_CreateTextureFromSurface(m_Renderer, m_SurfaceMessage);

        SDL_Rect Message_rect;
        Message_rect.w = 300;
        Message_rect.h = 100;
        Message_rect.x = SCREEN_WIDTH / 2 - Message_rect.w / 2;
        Message_rect.y = SCREEN_HEIGHT / 2 - Message_rect.h / 2;
        SDL_RenderCopy(m_Renderer, m_Message, NULL, &Message_rect);
    }

    // Present render
    SDL_RenderPresent(m_Renderer);
}

bool Engine::Clean()
{
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_FreeSurface(m_SurfaceMessage);
    SDL_DestroyTexture(m_Message);
    IMG_Quit();
    SDL_Quit();

    return true;
}

void Engine::Quit()
{
    m_IsRunning = false;
}