#ifndef __SDL_GRAPHIC__
#define __SDL_GRAPHIC__


#include <Resource.hpp>


struct SDL_Surface;
struct SDL_Texture;


class SDLGraphic : public Resource
{
    private:        
        SDL_Surface* surface = nullptr;
        SDL_Texture* texture = nullptr;

    public:
        SDLGraphic (const char* filePath);
        SDLGraphic (SDL_Surface* surface);

        void Dispose () override;
        SDL_Surface* GetSurface ();
        SDL_Texture* GetTexture ();
        bool IsValid () override;
        void Unload ();
};

#endif