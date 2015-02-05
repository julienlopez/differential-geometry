/*
 * iExpression.cpp
 *
 *  Created on: 4 févr. 2015
 *      Author: lopez
 */

#include "iexpression.hpp"

std::size_t iExpression::variableCount() const
{
	return impl_variableList().size();
}

std::set<Variable> iExpression::variableList() const
{
	return impl_variableList();
}

auto iExpression::derivative(const Variable& variable) const -> expression_up
{
	return impl_derivative(variable);
}

double iExpression::compute(const map_values_t& values) const
{
	return impl_compute(values);
}

void  iExpression::display(std::ostream& o) const
{
    return impl_display(o);
}