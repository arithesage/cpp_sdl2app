#include <Resources.hpp>

#include <Resource.hpp>
#include <Pool.hpp>


Pool<SDLGraphic> Resources::graphics;


Pool<SDLGraphic> Resources::Graphics ()
{
    return graphics;
}