#ifndef __SDL_RESOURCE_POOL__
#define __SDL_RESOURCE_POOL__

#include <any>

#ifndef __TYPES__
    #include <iostream>
    #include <unordered_map>

    using String = std::string;

    template <typename K, typename V>
    using Dictionary = std::unordered_map<K,V>;
#endif


enum class Resource
{
    Graphic
};


class ResourcePool
{
    private:
        static Dictionary<Resource, Dictionary<String, std::any>> pool;

    public:
        template <Resource R>
        void Store (String resourceName, std::any resource);
};


template <Resource R>
void ResourcePool::Store (String resourceName, std::any resource)
{
    
}
#endif