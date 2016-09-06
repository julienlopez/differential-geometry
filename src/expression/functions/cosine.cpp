#include "cosine.hpp"

#include "sine.hpp"

#include "../multiplication.hpp"
#include "../scalar.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

Cosine::Cosine(expression_up expression_): m_expression(std::move(expression_))
{
    assert(m_expression);
}

std::set<Variable> Cosine::impl_variableList() const
{
    return m_expression->variableList();
}

auto Cosine::impl_derivative(const Variable& variable) const -> expression_up
{
    auto der = m_expression->derivative(variable);
    const auto* p = dynamic_cast<Scalar*>(der.get());
    if(p && p->value() == 0) return std::make_unique<Scalar>(0);
    auto res = std::make_unique<Multiplication>();
    res->add(std::move(der));
    res->add(std::make_unique<Sine>(m_expression->clone()));
    return std::move(res);
}

double Cosine::impl_compute(const map_values_t& values) const
{
    return std::cos(m_expression->compute(values));
}

void Cosine::impl_display(std::ostream& o) const
{
    o << "cos(";
    m_expression->display(o);
    o << ")";
}

auto Cosine::impl_clone() const -> expression_up
{
    return std::make_unique<Cosine>(m_expression->clone());
}