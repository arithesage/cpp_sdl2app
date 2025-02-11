#ifndef __RESOURCES__
#define __RESOURCES__

class Resource;

class SDLGraphic;

template <typename R>
class Pool;


class Resources
{
    private:
        static Pool<SDLGraphic> graphics;

    public:
        Pool<SDLGraphic> Graphics ();
};

#endif