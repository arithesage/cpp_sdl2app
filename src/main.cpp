#include <SDL2/SDL.h>

#include <SDL.hpp>

#include <Logging.hpp>
#include <TTF_Module.hpp>
#include <ResourcePool.hpp>


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

    TTF_Module::Init (SDL::Renderer ());

    //ResourcePool::Store<Resource::Graphic>

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

    if (TTF_Module::IsValid ())
    {
        TTF_Module::Destroy ();
    }

    SDL::Shutdown ();

    return 0;
}








