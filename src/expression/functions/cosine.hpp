#pragma once

#include "../iexpression.hpp"

/**
* @invariant m_expression is valid
*/
class Cosine : public iExpression
{
public:
    /**
    * @precondition expression_ is valid
    */
    Cosine(expression_up expression_);

    virtual ~Cosine() = default;

private:
    expression_up m_expression;

    virtual std::set<Variable> impl_variableList() const override;

    virtual expression_up impl_derivative(const Variable& variable) const override;

    virtual double impl_compute(const map_values_t& values) const override;

    virtual void impl_display(std::ostream& o) const override;
};