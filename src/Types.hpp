#ifndef __TYPES__
#define __TYPES__

#include <iostream>
#include <map>
#include <vector>

using String = std::string;

template <typename Type>
using List = std::vector<Type>;

template <typename Key, typename Value>
using Dictionary = std::map<Key, Value>;

template <typename Key, typename Value>
using Map = std::map<Key, Value>;

#endif