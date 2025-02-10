#ifndef __SDL_SPRITE__
#define __SDL_SPRITE__


class SDLGraphic;


class Sprite
{
    private:
        int x = 0;
        int y = 0;

        SDLGraphic* graphic = nullptr;

    public:
        Sprite (SDLGraphic* graphic);
        ~Sprite ();

        int X ();
        int Y ();
        int Width ();
        int Height ();
};

#endif