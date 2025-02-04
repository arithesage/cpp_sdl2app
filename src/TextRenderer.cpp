#include <TextRenderer.hpp>

#include <SDL2/SDL.h>
#include <Logging.hpp>


TextRenderer::TextRenderer ()
{
    if (TTF_Init () < 0)
    {
        log_ec ("Failed initializing TrueType library.", SDL_GetError());
    }
    else
    {
        ready = true;

        //defaultFont = TTF_OpenFont (DEFAULT_FONTS_PATH + DEFAULT_FONT, 16)
    }
}


TextRenderer::~TextRenderer ()
{
    if (ready)
    {
        TTF_Quit ();
    }
}


bool TextRenderer::IsReady ()
{
    return ready;
}


void TextRenderer::SetFontsPath (const char* path)
{
    this->fonts = (char*)path;
}
