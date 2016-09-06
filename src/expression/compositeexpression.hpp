#pragma once

#include "iexpression.hpp"

#include <vector>

class CompositeExpression : public iExpression
{

public:
    virtual ~CompositeExpression() = default;

    void add(expression_up expr);

protected:
    CompositeExpression() = default;

    std::vector<expression_up> m_parts;

private:
    virtual std::set<Variable> impl_variableList() const override;

};
