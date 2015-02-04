/*
 * scalar.hpp
 *
 *  Created on: 4 févr. 2015
 *      Author: lopez
 */

#ifndef SCALAR_HPP_
#define SCALAR_HPP_

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
};

#endif /* SCALAR_HPP_ */
