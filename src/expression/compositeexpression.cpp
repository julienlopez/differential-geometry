#include "CompositeExpression.hpp"

void CompositeExpression::add(expression_up expr)
{
    m_parts.push_back(std::move(expr));
}

std::set<Variable> CompositeExpression::impl_variableList() const
{
    std::set<Variable> variables;
    for(const auto& expr : m_parts)
    {
        auto lst = expr->variableList();
        variables.insert(lst.begin(), lst.end());
    }
    return variables;
}
