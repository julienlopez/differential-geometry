#include "sum.hpp"

#include "scalar.hpp"

const std::string Sum::s_separator = " + ";

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
