#ifndef __FILESYSTEM__
#define __FILESYSTEM__

#include <Types.hpp>


class Filesystem
{
    private:
        static Filesystem* instance;

        Filesystem ();
        ~Filesystem ();
    
    public:
        static Filesystem* Get();

        String Path (String** parts);
};

#endif