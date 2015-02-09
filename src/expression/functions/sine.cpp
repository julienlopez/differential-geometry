#include "sine.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

Sine::Sine(expression_up expression_): m_expression(std::move(expression_))
{
    assert(m_expression);
}

std::set<Variable> Sine::impl_variableList() const
{
    return m_expression->variableList();
}

auto Sine::impl_derivative(const Variable& variable) const -> expression_up
{

}

double Sine::impl_compute(const map_values_t& values) const
{
    return std::sin(m_expression->compute(values));
}

void Sine::impl_display(std::ostream& o) const
{
    o << "sin(";
    m_expression->display(o);
    o << ")";
}