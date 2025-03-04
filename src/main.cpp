#include <SDL2/SDL.h>

#include <SDL.hpp>

#include <FontSupportModule.hpp>
#include <Resources.hpp>
#include <Logging.hpp>


int main ()
{
    const char* WINDOW_TITLE = "Test SDL App";
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
    
    SDL_Event event;

    if (!SDL::Init (WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        return 1;
    }

    FontSupportModule::Init (SDL::Renderer ());

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

        SDL::ClearWindow ();
        SDL::RefreshWindow ();
    }

    if (FontSupportModule::IsValid ())
    {
        FontSupportModule::Destroy ();
    }

    SDL::Shutdown ();

    return 0;
}








