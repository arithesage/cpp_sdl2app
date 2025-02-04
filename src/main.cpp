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
    SDL_Surface* screen = nullptr;

    if (SDL_Init (SDL_INIT_VIDEO) < 0)
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
        log_ec ("Failed creating window.", SDL_GetError());
        return 1;
    }

    screen = SDL_GetWindowSurface (window);
    
    SDL_FillRect (
        screen,
        nullptr,
        SDL_MapRGB (screen->format, 255, 255, 255)
    );

    SDL_UpdateWindowSurface (window);
    SDL_Delay (5000);
    SDL_DestroyWindow (window);
    SDL_Quit ();

    return 0;
}








