#pragma once

#include "compositeexpression.hpp"

class Sum : public CompositeExpression<Sum>
{
public:
	Sum() = default;

	virtual ~Sum() = default;

	static const std::string s_separator;

private:
	virtual expression_up impl_derivative(const Variable& variable) const override;

	virtual double impl_compute(const map_values_t& values) const override;
};
