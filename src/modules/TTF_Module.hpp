#ifndef __SDL_TTF_MODULE__
#define __SDL_TTF_MODULE__

#include <SDL2/SDL_ttf.h>

#include <Types.hpp>

struct SDL_Texture;


class TTF_Module
{
    private:
        const char* DEFAULT_FONTS_PATH = "res/fonts/";
        const char* DEFAULT_FONT = "NotoMoto-Regular.ttf";
        const int DEFAULT_FONT_SIZE = 16;

        static TTF_Module* instance;
        TTF_Font* defaultFont = nullptr;

        const char* fonts = "";
        Dictionary<String, TTF_Font*> loadedFonts;

        TTF_Module ();
        ~TTF_Module ();

    public:
        static void Destroy ();
        static TTF_Module* Get ();
        static void Init ();
        static bool IsValid ();
        
        SDL_Texture* RenderText (const char* text);
        void SetFontsPath (const char* path);
};

#endif