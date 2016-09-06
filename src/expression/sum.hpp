#pragma once

#include "iexpression.hpp"

#include <vector>

class Sum : public iExpression
{
public:
	Sum();
	virtual ~Sum() = default;

	void add(expression_up expr);

private:
	std::vector<expression_up> m_parts;

	virtual std::set<Variable> impl_variableList() const override;

	virtual expression_up impl_derivative(const Variable& variable) const override;

	virtual double impl_compute(const map_values_t& values) const override;

    virtual void impl_display(std::ostream& o) const override;
};
