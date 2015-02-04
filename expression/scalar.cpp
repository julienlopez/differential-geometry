/*
 * scalar.cpp
 *
 *  Created on: 4 févr. 2015
 *      Author: lopez
 */

#include "scalar.hpp"

#include "utils/make_unique.hpp"

Scalar::Scalar(double value_) noexcept : m_value(value_)
{}

double Scalar::value() const
{
	return m_value;
}

std::set<Variable> Scalar::impl_variableList() const
{
	return {};
}

auto Scalar::impl_derivative(const Variable&) const -> expression_up
{
	return utils::make_unique<Scalar>(0);
}

double Scalar::impl_compute(const map_values_t&) const
{
	return m_value;
}
