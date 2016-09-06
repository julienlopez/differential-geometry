#include "multiplication.hpp"
#include "sum.hpp"

#include "utils/algorithms.hpp"

#include <sstream>

auto Multiplication::impl_derivative(const Variable& variable) const -> expression_up
{
    const auto derivatives = utils::algorithms::buildFromTransform(m_parts, [&variable](const expression_up& p){ return p->derivative(variable); });
    auto res = std::make_unique<Sum>();
    for(std::size_t i = 0; i < m_parts.size(); i++)
    {
        auto product = std::make_unique<Multiplication>();
        for(std::size_t j = 0; j < m_parts.size(); j++)
        {
            if(i == j)
                product->add(derivatives[j]->clone());
            else
                product->add(m_parts[j]->clone());
        }
        res->add(std::move(product));
    }
    return std::move(res);
}

double Multiplication::impl_compute(const map_values_t& values) const
{
    double res = 1;
    for(const auto& value : m_parts)
        res *= value->compute(values);
    return res;
}

void Multiplication::impl_display(std::ostream& o) const
{
    static const std::string separator = " * ";
    std::ostringstream res;
    for(const auto& value : m_parts)
    {
        value->display(res);
        res << separator;
    }
    auto str = res.str();
    str.erase(str.size() - separator.size());
    o << str;
}

auto Multiplication::impl_clone() const -> expression_up
{
    auto res = std::make_unique<Multiplication>();
    for(const auto& p : m_parts)
        res->add(p->clone());
    return std::move(res);
}
