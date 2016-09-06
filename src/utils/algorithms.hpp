#pragma once

#include <algorithm>

namespace utils
{

    namespace algorithms
    {

        template<class CONTAINER, class VALUE>
        bool contains(const CONTAINER& container, const VALUE& value)
        {
            return std::find(std::begin(container), std::end(container), value) != std::end(container);
        }

    } // algorithms

} // utils

