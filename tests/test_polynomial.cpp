#include <gtest/gtest.h>

#include "expression/monomial.hpp"
#include "expression/scalar.hpp"
#include "expression/sum.hpp"

struct TestPolynomialOneVariable : public ::testing::Test
{
	TestPolynomialOneVariable(): sum(createSum())
	{}

	const Variable variable {"x"};
	const Sum sum;

private:
	Sum createSum()
	{
		Sum s;
		s.add(std::make_unique<Scalar>(3));
		s.add(std::make_unique<Monomial>(variable));
		s.add(std::make_unique<Monomial>(variable, 5, 2));
		return s;
	}
};

TEST_F(TestPolynomialOneVariable, VariableCount)
{
	ASSERT_EQ(1, sum.variableCount());
}

TEST_F(TestPolynomialOneVariable, VariableList)
{
	auto lst = sum.variableList();
	ASSERT_EQ(1, lst.size());
	ASSERT_EQ(variable, *lst.begin());
}

TEST_F(TestPolynomialOneVariable, Compute)
{
	ASSERT_EQ(3 + 9 + 5*9*9, sum.compute({{variable, 9}}));
}

TEST_F(TestPolynomialOneVariable, DerivativeSameVariable)
{
	const auto e = sum.derivative(variable);
	const auto* s2 = dynamic_cast<Sum*>(e.get());
	ASSERT_TRUE(s2);
	ASSERT_EQ(1 + 2*5*9, s2->compute({{variable, 9}}));
}

TEST_F(TestPolynomialOneVariable, Display)
{
    std::ostringstream ss;
    sum.display(ss);
    ASSERT_EQ("3 + x + 5x^2", ss.str());
}
