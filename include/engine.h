#pragma once
/*
    Init
    Event
    Clear
    Render
    Render present
    Wait
    Repeat
 */
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Engine
{

public:
    static Engine *GetInstance()
    {
        return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
    }

    bool Init();
    bool Clean();
    void Quit();

    void Events();
    void Update();
    void Render();

    bool IsRunning()
    {
        return m_IsRunning;
    }
    SDL_Renderer *GetRenderer() { return m_Renderer; }

private:
    Engine() {}
    bool m_IsRunning;
    static Engine *s_Instance;

    SDL_Window *m_Window;
    SDL_Renderer *m_Renderer;

    SDL_Point m_MousePos;
    SDL_Event m_Event;
    bool m_GameOver = false;

    SDL_Surface *m_SurfaceMessage;
    SDL_Texture *m_Message;

    TTF_Font *Sans = TTF_OpenFont("assets/font/Teko-Bold.ttf", 24);
    SDL_Color White = {255, 255, 255};
    std::string m_OutputText = "";
};
