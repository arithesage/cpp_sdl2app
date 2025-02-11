#ifndef __COLLIDER__
#define __COLLIDER__

struct SDL_Rect;


class Collider
{
    private:
        SDL_Rect* rect = nullptr;

    public:
        Collider ();
        Collider (int x, int y, int width, int height);

        ~Collider ();

        bool CollidesWith (Collider* other);

        SDL_Rect* Rect ();

        void Set (int x, int y);
        void Set (int x, int y, int width, int height);

        int X ();
        int Y ();
        int Width ();
        int Height ();
};

#endif