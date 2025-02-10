#include <SDLApp.hpp>

#include <SDL2/SDL.h>

#include <SDL.hpp>


SDLApp::SDLApp (const char* title, int width, int height)
{
    if (SDL::Init (title, width, height))
    {
        ready = true;

        #ifdef __SDL_TTF_MODULE__
            TTF_Module::Init (SDL::Renderer ());
        #endif
    }
}


SDLApp::~SDLApp ()
{
    
}


bool SDLApp::IsReady ()
{
    return ready;
}


bool SDLApp::IsRunning ()
{
    return running;
}


void SDLApp::Start () 
{
    SDL_Event event;

    OnStart ();

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

        OnUpdate ();
        OnRender ();

        SDL::RefreshWindow ();
    }

    quit ();
}


void SDLApp::OnStart () {}
void SDLApp::OnRender () {}
void SDLApp::OnUpdate () {}
void SDLApp::OnQuit () {}

void SDLApp::quit ()
{
    OnQuit ();

    #ifdef __SDL_TTF_MODULE__
        if (TTF_Module::IsValid ())
        {
            TTF_Module::Destroy ();
        }
    #endif

    SDL::Shutdown ();
}