#include <Sprite.hpp>

#include <SDLGraphic.hpp>

#include <Collider.hpp>


Sprite::Sprite (SDLGraphic* graphic)
{
    if (graphic != nullptr)
    {
        this->graphic = graphic;
        this->collider = new Collider ();
    }
}


Sprite::~Sprite ()
{
    graphic->Unload ();
}


bool Sprite::CollidesWith (Sprite* sprite)
{
    if (sprite == nullptr)
    {
        return false;
    }

    return collider->CollidesWith (sprite->collider);
}


int Sprite::X ()
{
    return x;
}


int Sprite::Y ()
{
    return y;
}


int Sprite::Width ()
{
    return -1;
}


int Sprite::Height ()
{
    return -1;
}

