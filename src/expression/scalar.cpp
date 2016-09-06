#include "scalar.hpp"

#include <iostream>

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
	return std::make_unique<Scalar>(0);
}

double Scalar::impl_compute(const map_values_t&) const
{
	return m_value;
}

void Scalar::impl_display(std::ostream& o) const
{
    o << m_value;
}
