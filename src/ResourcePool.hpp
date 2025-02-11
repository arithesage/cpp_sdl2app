#ifndef __SDL_RESOURCE_POOL__
#define __SDL_RESOURCE_POOL__

#ifndef __TYPES__
    #include <iostream>
    #include <unordered_map>

    using String = std::string;

    template <typename K, typename V>
    using Dictionary = std::unordered_map<K,V>;
#endif

#include <FilesystemHelpers.hpp>


template <typename Resource>
class ResourcePool
{
    private:
        static Dictionary<const char*, Resource> pool;

    public:
        Resource Get (const char* resourceName);
        void Load (const char* resourceName, const char* filePath);
        void Store (const char* resourceName, Resource resource);
};


template <typename Resource>
Dictionary<const char*, Resource> ResourcePool<Resource>::pool;


template <typename Resource>
Resource ResourcePool<Resource>::Get (const char* resourceName)
{
    return;
}


template <typename Resource>
void ResourcePool<Resource>::Load (const char* resourceName, 
                                   const char* filePath)
{

}


template <typename Resource>
void ResourcePool<Resource>::Store (const char* resourceName, 
                                    Resource resource)
{
    
}
#endif