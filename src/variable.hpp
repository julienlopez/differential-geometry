/*
 * variable.hpp
 *
 *  Created on: 4 févr. 2015
 *      Author: lopez
 */

#ifndef VARIABLE_HPP_
#define VARIABLE_HPP_

#include <string>

class Variable
{
public:
	explicit Variable(std::string name_) noexcept;
	~Variable() noexcept = default;

	Variable(const Variable&) = default;
	Variable(Variable&& v) noexcept;

	Variable& operator=(const Variable&) = default;
	Variable& operator=(Variable&& v) = default;

	const std::string name;

	bool operator==(const Variable& v) const;
	bool operator!=(const Variable& v) const;
};

bool operator<(const Variable& v1, const Variable& v2);

#endif /* VARIABLE_HPP_ */
