#pragma once

#include "iexpression.hpp"

class Monomial : public iExpression
{
public:
	Monomial(Variable variable_, double factor_ = 1, double power_ = 1);
	virtual ~Monomial() = default;

	Monomial(const Monomial& m);

	const Variable& variable() const;
	double factor() const;
	double power() const;

private:
	Variable m_variable;
	double m_factor;
	double m_power;

	virtual std::set<Variable> impl_variableList() const override;

	virtual expression_up impl_derivative(const Variable& variable) const override;

	virtual double impl_compute(const map_values_t& values) const override;

    virtual void impl_display(std::ostream& o) const override;

	virtual expression_up impl_clone() const override;
};
