#ifndef __SDL_TTF_MODULE__
#define __SDL_TTF_MODULE__

#include <SDL2/SDL_ttf.h>


class TTF_Module
{
    private:
        static TTF_Module* instance;

        const char* DEFAULT_FONTS_PATH = "res/fonts/";
        const char* DEFAULT_FONT = "NotoMoto-Regular.ttf";
        const int DEFAULT_FONT_SIZE = 16;

        char* fonts = "";

        TTF_Font* defaultFont = nullptr;        

        TTF_Module ();
        ~TTF_Module ();        

    public:
        static void Destroy ();
        static TTF_Module* Get ();
        static void Init ();
        static bool IsValid ();
        
        void SetFontsPath (const char* path);
};

#endif