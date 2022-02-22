#include "engine.h"
#include "variables.h"
#include "board.h"

Engine *Engine::s_Instance = nullptr;
Board board;

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

void Engine::Update()
{
    if (board.table[m_MousePos.y / CELL_HEIGHT][m_MousePos.x / CELL_WIDTH].player == 0)
    {
        board.table[m_MousePos.y / CELL_HEIGHT][m_MousePos.x / CELL_WIDTH].player = m_Player;
        if (m_Player == 1)
        {
            m_Player = 2;
        }
        else
        {
            m_Player = 1;
        }
    }

    // Debug, print out to console
    for (auto row = 0; row < N; row++)
    {
        for (auto col = 0; col < N; col++)
        {
            std::cout << board.table[row][col].player << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    // Check if we have a winner
    if (board.Solution() > 0)
    {
        std::cout << "Player " << board.Solution() << " has won!" << std::endl;
        Quit();
    }
}

void Engine::Render()
{
    // Render background
    SDL_SetRenderDrawColor(m_Renderer, bkgd.r, bkgd.g, bkgd.b, bkgd.a);
    SDL_RenderClear(m_Renderer);

    // Render board
    SDL_SetRenderDrawColor(m_Renderer, base.r, base.g, base.b, base.a);
    for (size_t i = 1; i < 3; i++)
    {
        SDL_RenderDrawLine(m_Renderer, CELL_WIDTH * i, 0, CELL_WIDTH * i, SCREEN_HEIGHT);
        SDL_RenderDrawLine(m_Renderer, 0, CELL_HEIGHT * i, SCREEN_WIDTH, CELL_HEIGHT * i);
    }

    // Present render
    SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
    // Handle events on queue
    while (SDL_PollEvent(&m_Event) != 0)
    {
        if (m_Event.type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_GetMouseState(&m_MousePos.x, &m_MousePos.y);
            Update();
            // SDL_Log("X: %d, Y: %d", m_MousePos.x, m_MousePos.y);
        }
        if (m_Event.type == SDL_QUIT)
        {
            Quit();
        }
    }
}

bool Engine::Clean()
{
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();

    return true;
}

void Engine::Quit()
{
    m_IsRunning = false;
}