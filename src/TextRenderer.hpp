#ifndef __SDL_TEXT_RENDERER__
#define __SDL_TEXT_RENDERER__

class TextRenderer
{
    private:
        const char* DEFAULT_FONTS_PATH = "res/fonts";
        const char* DEFAULT_FONT = "NotoMoto-Regular.ttf";

        char* fonts = "";

    public:
        TextRenderer ();
        ~TextRenderer ();

        void SetFontsPath (const char* path);
};

#endif