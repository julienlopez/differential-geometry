#pragma once

#include <iosfwd>
#include <map>
#include <memory>
#include <set>

#include "utils/noncopiable.hpp"

#include "variable.hpp"

class iExpression : private utils::noncopiable
{
public:
	using expression_up = std::unique_ptr<iExpression>;

	virtual ~iExpression() = default;

	std::size_t variableCount() const;

	std::set<Variable> variableList() const;

	expression_up derivative(const Variable& variable) const;

	using map_values_t = std::map<Variable, double>;
	double compute(const map_values_t& values) const;

    void display(std::ostream& o) const;

	expression_up clone() const;

protected:
	iExpression() = default;

private:
	virtual std::set<Variable> impl_variableList() const = 0;

	virtual expression_up impl_derivative(const Variable& variable) const = 0;

	virtual double impl_compute(const map_values_t& values) const = 0;

    virtual void impl_display(std::ostream& o) const = 0;

	virtual expression_up impl_clone() const = 0;

};
