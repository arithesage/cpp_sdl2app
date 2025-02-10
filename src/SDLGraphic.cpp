#include <SDLGraphic.hpp>

#include <SDL2/SDL.h>

#include <FilesystemHelpers.hpp>
#include <SDL.hpp>


SDLGraphic::SDLGraphic (const char* filePath)
{
    if (FSHelpers::IsFile (filePath))
    {
        
    }
}


SDLGraphic::SDLGraphic (SDL_Surface* surface)
{
    if (surface != nullptr)
    {
        this->surface = surface;
    }
}


SDLGraphic::~SDLGraphic ()
{
    Dispose ();
}


void SDLGraphic::Dispose ()
{
    Unload ();

    if (surface != nullptr)
    {
        SDL_FreeSurface (surface);
    }
}


SDL_Surface* SDLGraphic::GetSurface ()
{
    return surface;
}


SDL_Texture* SDLGraphic::GetTexture ()
{
    if (this->texture == nullptr)
    {
        this->texture = SDL_CreateTextureFromSurface (
            SDL::Renderer(), 
            this->surface
        );        
    }

    return texture;
}


bool SDLGraphic::IsValid ()
{
    return ((texture != nullptr) || (surface != nullptr));
}


void SDLGraphic::Unload ()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture (texture);
    }
}