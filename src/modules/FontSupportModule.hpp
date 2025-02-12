#ifndef __SDL_FONT_SUPPORT_MODULE__
#define __SDL_FONT_SUPPORT_MODULE__

#include <SDL2/SDL_ttf.h>

#include <Types.hpp>


struct SDL_Renderer;
struct SDL_Texture;


class FontSupportModule
{
    private:
        const char* DEFAULT_FONTS_PATH = "res/fonts/";
        const char* DEFAULT_FONT = "NotoMoto-Regular.ttf";
        const int DEFAULT_FONT_SIZE = 16;

        static FontSupportModule* instance;
        static bool ready;

        TTF_Font* defaultFont = nullptr;

        const char* fontsPath = "";
        Dictionary<String, TTF_Font*> loadedFonts;

        SDL_Renderer* renderer = nullptr;

        FontSupportModule ();
        ~FontSupportModule ();

    public:
        static void Destroy ();
        static FontSupportModule* Get ();
        static void Init (SDL_Renderer* renderer);
        static bool IsReady ();
        static bool IsValid ();
        
        SDL_Texture* RenderText (const char* text);
        void SetFontsPath (const char* path);
};

#endif