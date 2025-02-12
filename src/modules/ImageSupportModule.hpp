#ifndef __SDL_IMAGE_SUPPORT_MODULE__
#define __SDL_IMAGE_SUPPORT_MODULE__


#define IMG_FORMATS IMG_INIT_JPG | IMG_INIT_PNG | \
                    IMG_INIT_TIF | IMG_INIT_WEBP

struct SDL_Renderer;


class ImageSupportModule
{
    private:
        static bool ready;

        static ImageSupportModule* instance;

        ImageSupportModule ();
        ~ImageSupportModule ();
        
    public:
        static void Destroy ();
        static ImageSupportModule* Get ();
        static void Init (SDL_Renderer* renderer);
        static bool IsReady ();
        static bool IsValid ();
};

#endif