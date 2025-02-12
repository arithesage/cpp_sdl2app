#include <FontSupportModule.hpp>

#include <SDL2/SDL.h>

#include <FilesystemHelpers.hpp>
#include <Logging.hpp>
#include <Pool.hpp>
#include <SDL.hpp>
#include <SDLFont.hpp>


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
        fonts = new Pool<SDLFont> ();

        String defaultFontPath = FSHelpers::MakePath ({
            DEFAULT_FONTS_PATH,
            DEFAULT_FONT
        });

        if (!LoadFont ("default", defaultFontPath.c_str ()))
        {
            log_e ("Failed loading default font.");
        }
        else
        {
            defaultFont = fonts->Get("default").Font();
            ready = true;
        }
    }
}


FontSupportModule::~FontSupportModule ()
{
    if (FontSupportModule::IsReady ())
    {
        TTF_Quit ();
    }
}


void FontSupportModule::Init (SDL_Renderer* renderer)
{    
    if ((instance == nullptr) && (renderer != nullptr))
    {
        instance = new FontSupportModule ();
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


bool FontSupportModule::IsReady ()
{
    return ready;
}


bool FontSupportModule::IsValid ()
{
    return (instance != nullptr);
}


bool FontSupportModule::LoadFont (const char* name, const char* fontFileName)
{
    return LoadFont (name, fontFileName, DEFAULT_FONT_SIZE);
}


bool FontSupportModule::LoadFont (const char* name, 
                                  const char* fontFileName, 
                                  int size)
{
    String fontPath;

    if (fontsPath == "")
    {
        fontPath = String (DEFAULT_FONTS_PATH);
    }
    else
    {
        fontPath = String (fontsPath);
    }

    String fullFontPath = FSHelpers::MakePath ({fontPath, fontFileName});

    SDLFont font (fullFontPath.c_str(), size);

    if (!font.IsValid ())
    {
        return false;
    }

    fonts->Store (name, font);
    return true;
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
