#include <Filesystem.hpp>


Filesystem* Filesystem::instance = nullptr;


Filesystem* Filesystem::Get ()
{
    if (instance == nullptr)
    {
        instance = new Filesystem ();
    }

    return instance;
}


Filesystem::Filesystem ()
{

}


Filesystem::~Filesystem ()
{

}


String Filesystem::Path (String** parts)
{
    
}