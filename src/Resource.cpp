#include <Resource.hpp>

#include <FilesystemHelpers.hpp>


Resource::Resource (const char* filePath)
{
    exists = FSHelpers::IsFile (filePath);
}


Resource::~Resource ()
{
    if (IsValid ())
    {
        Dispose ();
    }
}


void Resource::Dispose () {}



