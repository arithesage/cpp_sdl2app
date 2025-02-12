#include <FontSupportModule.hpp>

#include <SDL2/SDL.h>

#include <FilesystemHelpers.hpp>
#include <Logging.hpp>
#include <SDL.hpp>


FontSupportModule* FontSupportModule::instance = nullptr;
bool FontSupportModule::ready = false;


FontSupportModule::FontSupportModule ()
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


FontSupportModule::~FontSupportModule ()
{
    if (FontSupportModule::IsReady ())
    {
        TTF_Quit ();
    }
}


void FontSupportModule::Destroy ()
{
    if (IsValid ())
    {
        delete instance;
    }
}


FontSupportModule* FontSupportModule::Get ()
{
    if (!IsValid ())
    {
        log_e ("FontSupport module has not been initialized yet!");
        return nullptr;
    }

    return instance;
}


void FontSupportModule::Init (SDL_Renderer* renderer)
{    
    if ((instance == nullptr) && (renderer != nullptr))
    {
        instance = new FontSupportModule ();
    }
}


bool FontSupportModule::IsReady ()
{
    return ready;
}


bool FontSupportModule::IsValid ()
{
    return (instance != nullptr);
}


SDL_Texture* FontSupportModule::RenderText (const char* text)
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


void FontSupportModule::SetFontsPath (const char* path)
{
    fontsPath = (char*) path;
}
