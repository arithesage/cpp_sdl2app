#include <iostream>
#include <SDL2/SDL.h>


void log_e (const char* message)
{
    std::cerr << "[ERROR]: " << message << std::endl; 
}


void log_ec (const char* error, const char* cause)
{
    log_e (error);
    std::cerr << "[CAUSE]: " << cause << std::endl;
    std::cerr << std::endl;
}


int main ()
{
    const char* WINDOW_TITLE = "Test SDL App";
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* screen = nullptr;

    SDL_Event event;

    if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
    {
        log_ec ("Failed initializing SDL.", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow (
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr)
    {
        log_ec ("Failed creating window.", SDL_GetError ());
        return 1;
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
        return 1;
    }

    bool running = true;

    while (running)
    {
        if (SDL_PollEvent (&event) > 0)
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }

        SDL_SetRenderDrawColor (
            renderer,
            0, 0, 0, 1
        );

        SDL_RenderClear (renderer);
        SDL_RenderPresent (renderer);
    }
    
    SDL_DestroyRenderer (renderer);
    SDL_DestroyWindow (window);
    SDL_Quit ();

    return 0;
}








