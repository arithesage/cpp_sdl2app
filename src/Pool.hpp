#ifndef __POOL__
#define __POOL__

#ifndef __TYPES__
    #include <iostream>
    #include <unordered_map>

    using String = std::string;

    template <typename K, typename V>
    using Dictionary = std::unordered_map<K,V>;
#endif

class Resource;


template <typename R = Resource>
class Pool
{
    private:
        static Dictionary<const char*, R> pool;

    public:
        R Get (const char* resourceName);
        void Load (const char* resourceName, const char* filePath);
        void Store (const char* resourceName, R resource);
};


template <typename R>
Dictionary<const char*, R> Pool<R>::pool;


template <typename R>
R Pool<R>::Get (const char* resourceName)
{
    return;
}


template <typename R>
void Pool<R>::Load (const char* resourceName, const char* filePath)
{

}


template <typename R>
void Pool<R>::Store (const char* resourceName, R resource)
{
    
}
#endif