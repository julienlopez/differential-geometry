/*
 * sum.hpp
 *
 *  Created on: 4 févr. 2015
 *      Author: lopez
 */

#ifndef SUM_HPP_
#define SUM_HPP_

#include "iexpression.hpp"

#include <vector>

class Sum : public iExpression
{
public:
	Sum();
	virtual ~Sum() = default;

	Sum(Sum&& s);

	void add(expression_up expr);

private:
	std::vector<expression_up> m_parts;

	virtual std::set<Variable> impl_variableList() const override;

	virtual expression_up impl_derivative(const Variable& variable) const override;

	virtual double impl_compute(const map_values_t& values) const override;

    virtual void impl_display(std::ostream& o) const override;
};

#endif /* SUM_HPP_ */
