#ifndef __SDL_IMAGE_MODULE__
#define __SDL_IMAGE_MODULE__


struct SDL_Renderer;


class Image_Module
{
    private:
        const int IMG_FORMATS = IMG_INIT_JPG | IMG_INIT_PNG | 
                                IMG_INIT_TIF | IMG_INIT_WEBP;

        static bool ready;

        static Image_Module* instance;
        
    public:
        static void Destroy ();
        static Image_Module* Get ();
        static void Init (SDL_Renderer* renderer);
        static bool IsReady ();
        static bool IsValid ();
};

#endif