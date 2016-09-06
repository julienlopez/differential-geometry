#pragma once

#include "iexpression.hpp"

#include <sstream>
#include <vector>

template<class CRTP>
class CompositeExpression : public iExpression
{

public:
    virtual ~CompositeExpression() = default;

    void add(expression_up expr)
    {
        m_parts.push_back(std::move(expr));
    }

protected:
    CompositeExpression() = default;

    std::vector<expression_up> m_parts;

private:
    virtual std::set<Variable> impl_variableList() const override
    {
        std::set<Variable> variables;
        for(const auto& expr : m_parts)
        {
            auto lst = expr->variableList();
            variables.insert(lst.begin(), lst.end());
        }
        return variables;
    }

    void impl_display(std::ostream& o) const
    {
        std::ostringstream res;
        for(const auto& value : m_parts)
        {
            value->display(res);
            res << CRTP::s_separator;
        }
        auto str = res.str();
        str.erase(str.size() - CRTP::s_separator.size());
        o << str;
    }

    auto impl_clone() const -> expression_up
    {
        auto res = std::make_unique<CRTP>();
        for(const auto& p : m_parts)
            res->add(p->clone());
        return std::move(res);
    }

};
