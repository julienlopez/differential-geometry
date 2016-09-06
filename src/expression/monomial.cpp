#include "monomial.hpp"
#include "scalar.hpp"

#include <cmath>
#include <iostream>

Monomial::Monomial(Variable variable_, double factor_, double power_):
	m_variable(variable_), m_factor(factor_), m_power(power_)
{}

Monomial::Monomial(const Monomial& m): m_variable(m.m_variable), m_factor(m.m_factor), m_power(m.m_power)
{}

const Variable& Monomial::variable() const
{
	return m_variable;
}

double Monomial::factor() const
{
	return m_factor;
}

double Monomial::power() const
{
	return m_power;
}

std::set<Variable> Monomial::impl_variableList() const
{
	return {m_variable};
}

auto Monomial::impl_derivative(const Variable& var) const -> expression_up
{
	if(var != m_variable) return std::make_unique<Monomial>(*this);
	if(m_power == 1) return std::make_unique<Scalar>(m_factor);
	return std::make_unique<Monomial>(m_variable, m_factor * m_power, m_power-1);
}

double Monomial::impl_compute(const map_values_t& values) const
{
	auto it = values.find(m_variable);
	if(it == values.end())
	{
		throw std::invalid_argument("unable to find variable `" + m_variable.name + "` in varibale list");
	}
	return m_factor * std::pow(it->second, m_power);
}

void Monomial::impl_display(std::ostream& o) const
{
    if(m_factor != 1)
    {
        o << m_factor;
    }
    o << m_variable.name;
    if(m_power == 1) return;
    o << "^" << m_power;
}

auto Monomial::impl_clone() const -> expression_up
{
	return std::make_unique<Monomial>(*this);
}
