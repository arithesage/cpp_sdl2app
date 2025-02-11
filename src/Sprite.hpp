#ifndef __SDL_SPRITE__
#define __SDL_SPRITE__


class SDLGraphic;

class Collider;

class Sprite
{
    private:
        int x = 0;
        int y = 0;

        SDLGraphic* graphic = nullptr;
        Collider* collider = nullptr;

    public:
        Sprite (SDLGraphic* graphic);
        ~Sprite ();

        bool CollidesWith (Sprite* sprite);

        int X ();
        int Y ();
        int Width ();
        int Height ();
};

#endif