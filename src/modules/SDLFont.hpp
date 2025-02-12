#ifndef __RESOURCE_SDL_FONT__
#define __RESOURCE_SDL_FONT__

#include <SDL2/SDL_ttf.h>

#include <Resource.hpp>


class SDLFont : public Resource
{
    private:
        const int DEFAULT_SIZE = 16;

        TTF_Font* font = nullptr;

    public:
        SDLFont ();
        SDLFont (const char* filePath);
        SDLFont (const char* filePath, int size);

        SDLFont& operator=(const SDLFont& other);
        
        TTF_Font* Font ();

        void Dispose () override;
        bool IsValid () override;
};

#endif