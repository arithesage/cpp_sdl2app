#ifndef __TYPES__
#define __TYPES__

#include <iostream>
#include <map>
#include <type_traits>
#include <vector>


using String = std::string;

template <typename Type>
using List = std::vector<Type>;

template <typename Key, typename Value>
using Dictionary = std::map<Key, Value>;

template <typename Key, typename Value>
using Map = std::map<Key, Value>;




// Special class for testing types
template <typename This>
class Type
{
    public:
        // Returns if Other inherits from This type
        template <typename Base>
        static bool InheritsFrom ()
        {
            return std::is_base_of<Base,This>::value;
        }

        // Returns if This type is a pointer.
        // Intended for use with templated types.
        static bool IsPtr ()
        {
            return std::is_pointer<This>::value;
        }
};

#endif
