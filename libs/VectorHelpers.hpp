#ifndef __VECTOR_HELPERS__
#define __VECTOR_HELPERS__

#include <initializer_list>
#include <vector>

#ifndef __TYPES__
    template <typename Type>
    using List = std::vector<Type>;
#endif


class VectorHelpers
{
    public:
        /**
         * Returns a vector containing all the provided items.
         * The items must be provided betwee { and }.
         * Example: Pack<const char*> ({ "one", "two" })
         */
        template <typename ItemType>
        static List<ItemType> Pack (std::initializer_list<ItemType> items)
        {
            List<ItemType> list;

            for (ItemType item : items)
            {
                list.push_back (item);
            }

            return list;
        }
};

#endif
