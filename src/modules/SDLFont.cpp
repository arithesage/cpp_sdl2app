#include <SDLFont.hpp>

#include <Logging.hpp>


SDLFont::SDLFont () : Resource ()
{

}


SDLFont::SDLFont (const char* filePath)
: SDLFont (filePath, DEFAULT_SIZE)
{
    
}


SDLFont::SDLFont (const char* filePath, int size) : Resource (filePath)
{
    if (exists)
    {
        font = TTF_OpenFont (filePath, size);

        if (!IsValid ())
        {
            log_e ("Failed loading font.");
        }
    }
}


SDLFont& SDLFont::operator=(const SDLFont& other)
{
    this->font = other.font;
    return *this;
}


TTF_Font* SDLFont::Font ()
{
    return font;
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