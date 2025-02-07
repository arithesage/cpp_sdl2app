#include <FilesystemHelpers.hpp>

#include <StringHelpers.hpp>


bool FilesystemHelpers::IsFile (const char * path)
{
    return IsFile (String (path));
}


bool FilesystemHelpers::IsFile (String path)
{
    std::ifstream file;
    
    file.open (path);

    if (file.is_open())
    {
        file.close ();
        return true;
    }

    return false;
}


String FilesystemHelpers::MakePath (std::initializer_list<String> pathParts)
{
    String path = StringHelpers::Concat (pathParts, "/");
    return path;
}