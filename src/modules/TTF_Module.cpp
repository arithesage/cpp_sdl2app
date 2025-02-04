#include <TTF_Module.hpp>

#include <SDL2/SDL.h>
#include <Logging.hpp>


TTF_Module* TTF_Module::instance = nullptr;


TTF_Module::TTF_Module ()
{
    if (TTF_Init () < 0)
    {
        log_ec ("Failed initializing TrueType library.", SDL_GetError());
    }
    else
    {
        //defaultFont = TTF_OpenFont (DEFAULT_FONTS_PATH + DEFAULT_FONT, 16)
    }
}


TTF_Module::~TTF_Module ()
{
    if (TTF_Module::IsValid ())
    {
        TTF_Quit ();
    }
}


void TTF_Module::Destroy ()
{
    if (IsValid ())
    {
        delete instance;        
    }
}


TTF_Module* TTF_Module::Get ()
{
    if (instance == nullptr)
    {
        Init ();
    }

    return instance;
}


void TTF_Module::Init ()
{
    if (instance == nullptr)
    {
        instance = new TTF_Module ();
    }
}


bool TTF_Module::IsValid ()
{
    return (instance != nullptr);
}


void TTF_Module::SetFontsPath (const char* path)
{
    this->fonts = (char*)path;
}
