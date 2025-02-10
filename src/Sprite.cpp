#include <Sprite.hpp>

#include <SDLGraphic.hpp>


Sprite::Sprite (SDLGraphic* graphic)
{
    if (graphic != nullptr)
    {
        this->graphic = graphic;
    }
}


Sprite::~Sprite ()
{
    graphic->Unload ();
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

