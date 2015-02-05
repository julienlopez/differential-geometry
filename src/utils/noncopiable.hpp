/*
 * noncopiable.hpp
 *
 *  Created on: 4 févr. 2015
 *      Author: lopez
 */

#ifndef NONCOPIABLE_HPP_
#define NONCOPIABLE_HPP_

namespace utils {

struct noncopiable
{
	noncopiable() noexcept = default;
	~noncopiable() noexcept = default;

	noncopiable(const noncopiable&) noexcept = delete;
	noncopiable& operator=(const noncopiable&) noexcept = delete;

	noncopiable(noncopiable&&) noexcept = default;
	noncopiable& operator=(noncopiable&&) noexcept = default;
};

}

#endif /* NONCOPIABLE_HPP_ */
