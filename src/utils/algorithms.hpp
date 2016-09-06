#pragma once

#include <algorithm>
#include <cassert>

namespace utils
{

    namespace algorithms
    {

        template<class Container, class Value>
        bool contains(const Container& container, const Value& value)
        {
            return std::find(std::begin(container), std::end(container), value) != std::end(container);
        }

        /***
         * @post return.size() == container.size()
         */
        template<class Container, class UnaryOperation>
        auto buildFromTransform(const Container& container, UnaryOperation fct)
        {
            std::vector<decltype(fct(container.front()))> result;
            result.reserve(container.size());
            std::transform(std::begin(container), std::end(container), std::back_inserter(result), fct);
            assert(result.size() == container.size());
            return result;
        }

    } // algorithms

} // utils

