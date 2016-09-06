#include "sum.hpp"

#include "scalar.hpp"

#include <sstream>

auto Sum::impl_derivative(const Variable& variable) const -> expression_up
{
	auto res = std::make_unique<Sum>();
	for(const auto& value : m_parts)
	{
		auto deriv = value->derivative(variable);
		auto* scalar = dynamic_cast<Scalar*>(deriv.get());
		if(scalar)
		{
			if(scalar->value() == 0) continue;
		}
		res->add(std::move(deriv));
	}
	return std::move(res);
}

double Sum::impl_compute(const map_values_t& values) const
{
	double res = 0;
	for(const auto& value : m_parts)
		res += value->compute(values);
	return res;
}

void Sum::impl_display(std::ostream& o) const
{
    static const std::string separator = " + ";
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

auto Sum::impl_clone() const -> expression_up
{
	auto res = std::make_unique<Sum>();
	for(const auto& p : m_parts)
		res->add(p->clone());
	return std::move(res);
}

