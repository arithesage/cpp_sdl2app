#include <Collider.hpp>

#include <SDL2/SDL.h>


Collider::Collider ()
{
    rect = new SDL_Rect ();
}


Collider::Collider (int x, int y, int width, int height)
{
    rect = new SDL_Rect ();
    Set (x, y, width, height);
}


Collider::~Collider ()
{
    delete rect;
}


bool Collider::CollidesWith (Collider* other)
{
    if (other == nullptr)
    {
        return false;
    }

    SDL_Rect result;

    SDL_bool collision = SDL_IntersectRect (
        rect, 
        other->rect,
        &result
    );

    return (collision == SDL_TRUE);
}


SDL_Rect* Collider::Rect ()
{
    return rect;
}


void Collider::Set (int x, int y)
{
    rect->x = x;
    rect->y = y;
}


void Collider::Set (int x, int y, int width, int height)
{
    rect->x = x;
    rect->y = y;
    rect->w = width;
    rect->h = height;
}


int Collider::X ()
{
    return rect->x;
}


int Collider::Y ()
{
    return rect->y;
}


int Collider::Width ()
{
    return rect->w;
}


int Collider::Height ()
{
    return rect->h;
}


