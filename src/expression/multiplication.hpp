#pragma once

#include "compositeexpression.hpp"

class Multiplication : public CompositeExpression
{
    public:
        Multiplication() = default;

        virtual ~Multiplication() = default;

    private:
        virtual expression_up impl_derivative(const Variable& variable) const override;

        virtual double impl_compute(const map_values_t& values) const override;

        virtual void impl_display(std::ostream& o) const override;

        virtual expression_up impl_clone() const override;

};



