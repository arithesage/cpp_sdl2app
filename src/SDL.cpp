#include <SDL.hpp>

#include <SDL2/SDL.h>

#include <Logging.hpp>


SDL_Renderer* SDL::renderer = nullptr;
SDL_Window* SDL::window = nullptr;


bool SDL::Init (const char* windowTitle,
                int width,
                int height)
{
    if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
    {
        log_ec ("Failed initializing SDL.", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow (
        windowTitle,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr)
    {
        log_ec ("Failed creating window.", SDL_GetError ());
        return false;
    }

    renderer = SDL_CreateRenderer (
        window, 
        -1,
        SDL_RENDERER_ACCELERATED | 
        SDL_RENDERER_PRESENTVSYNC |
        SDL_RENDERER_TARGETTEXTURE
    );

    if (renderer == nullptr)
    {
        log_ec ("Failed creating renderer.", SDL_GetError ());
        return false;
    }

    return true;
}


void SDL::Shutdown ()
{
    SDL_DestroyRenderer (renderer);
    SDL_DestroyWindow (window);
    SDL_Quit ();
}


void SDL::ClearWindow ()
{
    SDL_RenderClear (renderer);
}


void SDL::RefreshWindow ()
{
    SDL_RenderPresent (renderer);
}


SDL_Renderer* SDL::Renderer ()
{
    return renderer;
}


void SDL::SetClearColor (SDL_Color color)
{
    SDL_SetRenderDrawColor (renderer, color.r, color.g, color.b, color.a);
}


SDL_Window* SDL::Window ()
{
    return window;
}