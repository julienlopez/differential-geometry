#pragma once

#include "compositeexpression.hpp"

class Multiplication : public CompositeExpression<Multiplication>
{
    public:
        Multiplication() = default;

        virtual ~Multiplication() = default;

        static const std::string s_separator;

    private:
        virtual expression_up impl_derivative(const Variable& variable) const override;

        virtual double impl_compute(const map_values_t& values) const override;
};



