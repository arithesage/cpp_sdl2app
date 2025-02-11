#include <Image_Module.hpp>

#include <SDL2/SDL_image.h>

#include <Logging.hpp>


Image_Module* Image_Module::instance = nullptr;
bool Image_Module::ready = false;


Image_Module::Image_Module ()
{
    if (IMG_Init (IMG_FORMATS) != IMG_FORMATS)
    {
        log_ec ("Failed initializing SDL_image.", SDL_GetError());
    }
    else
    {
        ready = true;
    }
}

Image_Module::~Image_Module ()
{
    if (Image_Module::IsReady ())
    {
        IMG_Quit ();
    }
}


void Image_Module::Destroy ()
{
    if (IsValid ())
    {
        delete instance;
    }
}


Image_Module* Image_Module::Get ()
{
    if (!IsValid ())
    {
        log_e ("Image_Module has not been initialized yet!");
        return nullptr;
    }

    return instance;
}


void Image_Module::Init (SDL_Renderer* renderer)
{    
    if ((instance == nullptr) && (renderer != nullptr))
    {
        instance = new Image_Module ();
    }
}


bool Image_Module::IsReady ()
{
    return ready;
}


bool Image_Module::IsValid ()
{
    return (instance != nullptr);
}