#ifndef __SDL_TEXT_RENDERER__
#define __SDL_TEXT_RENDERER__

#include <SDL2/SDL_ttf.h>


class TextRenderer
{
    private:
        const char* DEFAULT_FONTS_PATH = "res/fonts/";
        const char* DEFAULT_FONT = "NotoMoto-Regular.ttf";
        const int DEFAULT_FONT_SIZE = 16;

        char* fonts = "";

        TTF_Font* defaultFont = nullptr;

        bool ready = false;

    public:
        TextRenderer ();
        ~TextRenderer ();

        bool IsReady ();
        void SetFontsPath (const char* path);
};

#endif