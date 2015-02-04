/*
 * sum.cpp
 *
 *  Created on: 4 févr. 2015
 *      Author: lopez
 */

#include "sum.hpp"
#include "scalar.hpp"

#include "utils/make_unique.hpp"

Sum::Sum()
{}

Sum::Sum(Sum&& s): m_parts(std::move(s.m_parts))
{}

void Sum::add(expression_up expr)
{
	m_parts.push_back(std::move(expr));
}

std::set<Variable> Sum::impl_variableList() const
{
	std::set<Variable> variables;
	for(const auto& expr : m_parts)
	{
		auto lst = expr->variableList();
		variables.insert(lst.begin(), lst.end());
	}
	return variables;
}

auto Sum::impl_derivative(const Variable& variable) const -> expression_up
{
	auto res = utils::make_unique<Sum>();
	for(const auto& value : m_parts)
	{
		auto deriv = value->derivative(variable);
		auto* scalar = dynamic_cast<Scalar*>(deriv.get());
		if(scalar)
		{
			if(scalar->value() == 0) continue;
		}
		res->add(std::move(deriv));
	}
	return std::move(res);
}

double Sum::impl_compute(const map_values_t& values) const
{
	double res = 0;
	for(const auto& value : m_parts)
		res += value->compute(values);
	return res;
}

