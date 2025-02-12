#include <ImageSupportModule.hpp>

#include <SDL2/SDL_image.h>

#include <Logging.hpp>


ImageSupportModule* ImageSupportModule::instance = nullptr;
bool ImageSupportModule::ready = false;


ImageSupportModule::ImageSupportModule ()
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


ImageSupportModule::~ImageSupportModule ()
{
    if (ImageSupportModule::IsReady ())
    {
        IMG_Quit ();
    }
}


void ImageSupportModule::Destroy ()
{
    if (IsValid ())
    {
        delete instance;
    }
}


ImageSupportModule* ImageSupportModule::Get ()
{
    if (!IsValid ())
    {
        log_e ("ImageSupport module has not been initialized yet!");
        return nullptr;
    }

    return instance;
}


void ImageSupportModule::Init (SDL_Renderer* renderer)
{    
    if ((instance == nullptr) && (renderer != nullptr))
    {
        instance = new ImageSupportModule ();
    }
}


bool ImageSupportModule::IsReady ()
{
    return ready;
}


bool ImageSupportModule::IsValid ()
{
    return (instance != nullptr);
}