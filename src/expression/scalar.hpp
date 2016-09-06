#pragma once

#include "iexpression.hpp"

class Scalar : public iExpression
{
public:
	explicit Scalar(double value_) noexcept;
	virtual ~Scalar() noexcept = default;

	double value() const;

private:
	double m_value;

	virtual std::set<Variable> impl_variableList() const override;

	virtual expression_up impl_derivative(const Variable& variable) const override;

	virtual double impl_compute(const map_values_t& values) const override;

    virtual void impl_display(std::ostream& o) const override;

	virtual expression_up impl_clone() const override;

};
