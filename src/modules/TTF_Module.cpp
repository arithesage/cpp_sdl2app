#include <TTF_Module.hpp>

#include <SDL2/SDL.h>

#include <FilesystemHelpers.hpp>
#include <Logging.hpp>
#include <SDL.hpp>


TTF_Module* TTF_Module::instance = nullptr;
bool TTF_Module::ready = false;


TTF_Module::TTF_Module ()
{
    if (TTF_Init () < 0)
    {
        log_ec ("Failed initializing TrueType library.", SDL_GetError());
    }
    else
    {
        String defaultFontPath = FSHelpers::MakePath ({
            DEFAULT_FONTS_PATH,
            DEFAULT_FONT
        });

        if (FSHelpers::IsFile (defaultFontPath))
        {
            defaultFont = TTF_OpenFont (
                defaultFontPath.c_str(), 
                DEFAULT_FONT_SIZE
            );
        }

        ready = true;
    }
}


TTF_Module::~TTF_Module ()
{
    if (TTF_Module::IsReady ())
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
    if (!IsValid ())
    {
        log_e ("TTF_Module has not been initialized yet!");
        return nullptr;
    }

    return instance;
}


void TTF_Module::Init (SDL_Renderer* renderer)
{    
    if ((instance == nullptr) && (renderer != nullptr))
    {
        instance = new TTF_Module ();
    }
}


bool TTF_Module::IsReady ()
{
    return ready;
}


bool TTF_Module::IsValid ()
{
    return (instance != nullptr);
}


SDL_Texture* TTF_Module::RenderText (const char* text)
{
    if (!ready)
    {
        log_e ("TTF_Module is not ready yet.");
        return nullptr;
    }

    TTF_Font* font = defaultFont;
    SDL_Color color = { 255, 255, 255 };

    SDL_Surface* surface = TTF_RenderText_Solid (defaultFont, text, color);

    if (surface == nullptr)
    {
        return nullptr;
    }

    SDL_Texture* renderedText = SDL_CreateTextureFromSurface (
        renderer,
        surface
    );

    return renderedText;
}


void TTF_Module::SetFontsPath (const char* path)
{
    fontsPath = (char*) path;
}
