#ifndef __SDL_GRAPHIC__
#define __SDL_GRAPHIC__


struct SDL_Surface;
struct SDL_Texture;


class SDLGraphic
{
    private:
        const char* filePath = "";
        
        SDL_Surface* surface = nullptr;
        SDL_Texture* texture = nullptr;

    public:
        SDLGraphic (const char* filePath);
        SDLGraphic (SDL_Surface* surface);

        ~SDLGraphic ();

        void Dispose ();
        SDL_Surface* GetSurface ();
        SDL_Texture* GetTexture ();
        bool IsValid ();
        void Unload ();
};

#endif