#ifndef __SDL_FONT_SUPPORT_MODULE__
#define __SDL_FONT_SUPPORT_MODULE__

#include <SDL2/SDL_ttf.h>

#include <Types.hpp>


struct SDL_Renderer;
struct SDL_Texture;

template <typename Resource>
class Pool;

class SDLFont;


class FontSupportModule
{
    private:
        const char* DEFAULT_FONTS_PATH = "res/fonts/";
        const char* DEFAULT_FONT = "NotoMoto-Regular.ttf";
        const int DEFAULT_FONT_SIZE = 16;

        static FontSupportModule* instance;

        static bool ready;

        TTF_Font* defaultFont = nullptr;
        Pool<SDLFont>* fonts = nullptr;
        SDL_Renderer* renderer = nullptr;

        const char* fontsPath = "";

        FontSupportModule ();
        ~FontSupportModule ();

    public:
        static void Init (SDL_Renderer* renderer);
        static void Destroy ();
        
        static FontSupportModule* Get ();
        static bool IsReady ();
        static bool IsValid ();
        
        bool LoadFont (const char* name, const char* filePath);
        bool LoadFont (const char* name, const char* filePath, int size);
        
        SDL_Texture* RenderText (const char* text);
        void SetFontsPath (const char* path);
};

#endif