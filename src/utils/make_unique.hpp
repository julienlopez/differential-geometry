/*
 * make_unique.hpp
 *
 *  Created on: 4 févr. 2015
 *      Author: lopez
 */

#ifndef MAKE_UNIQUE_HPP_
#define MAKE_UNIQUE_HPP_

#include <memory>

namespace utils {

template<class T, class... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}

#endif /* MAKE_UNIQUE_HPP_ */
