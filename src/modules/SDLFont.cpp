#include <SDLFont.hpp>


SDLFont::SDLFont (const char* filePath)
: SDLFont (filePath, DEFAULT_SIZE)
{
    
}


SDLFont::SDLFont (const char* filePath, int size) : Resource (filePath)
{
    if (exists)
    {
        font = TTF_OpenFont (filePath, size);
    }
}


void SDLFont::Dispose ()
{
    if (IsValid ())
    {
        TTF_CloseFont (font);
    }
}


bool SDLFont::IsValid ()
{
    return (font != nullptr);
}