#include <gtest/gtest.h>

#include <cmath>

#include "expression/monomial.hpp"
#include "expression/scalar.hpp"

struct TestMonomialPowerOfOne : public ::testing::Test
{
	const Variable variable{"x"};
	const double factor {20.1};
	const double power {1};
	const Monomial m {variable, factor, power};
};

TEST_F(TestMonomialPowerOfOne, TestConstructor)
{
	ASSERT_EQ(variable, m.variable());
	ASSERT_EQ(factor, m.factor());
	ASSERT_EQ(power, m.power());
}

TEST_F(TestMonomialPowerOfOne, TestVariableCount)
{
	ASSERT_EQ(1, m.variableCount());
}

TEST_F(TestMonomialPowerOfOne, TestVariableList)
{
	const auto lst = m.variableList();
	ASSERT_EQ(1, lst.size());
	ASSERT_EQ(variable, *lst.begin());
}

TEST_F(TestMonomialPowerOfOne, DerivateSameVariable)
{
	auto d = m.derivative(variable);
	const auto* m2 = dynamic_cast<Scalar*>(d.get());
	ASSERT_TRUE(m2);
	ASSERT_EQ(factor, m2->value());
}

TEST_F(TestMonomialPowerOfOne, DerivateOtherVariable)
{
	auto d = m.derivative(Variable("a"));
	const auto* m2 = dynamic_cast<Monomial*>(d.get());
	ASSERT_TRUE(m2);
	ASSERT_EQ(factor, m2->factor());
	ASSERT_EQ(variable, m2->variable());
	ASSERT_EQ(power, m2->power());
}

TEST_F(TestMonomialPowerOfOne, Value)
{
	const double value = 3;
	ASSERT_EQ(factor * std::pow(value, power), m.compute({{variable, value}}));
}

TEST_F(TestMonomialPowerOfOne, ThrowIfValueWithoutGoodVariable)
{
	ASSERT_THROW(m.compute({{Variable("a"), 5}}), std::invalid_argument);
}

TEST_F(TestMonomialPowerOfOne, Display)
{
    std::ostringstream ss;
    m.display(ss);
    ASSERT_EQ("20.1x", ss.str());
}

struct TestMonomialPowerOfTwo : public ::testing::Test
{
	const double factor = {10};
	const double power = {2};
	const Variable variable {"x"};
	const Monomial m = {variable, factor, power};
};

TEST_F(TestMonomialPowerOfTwo, DerivatePowerOfTwo)
{
	auto d = m.derivative(variable);
	const auto* m2 = dynamic_cast<Monomial*>(d.get());
	ASSERT_TRUE(m2);
	ASSERT_EQ(variable, m2->variable());
	ASSERT_EQ(power - 1, m2->power());
	ASSERT_EQ(power*factor, m2->factor());
}

TEST_F(TestMonomialPowerOfTwo, Value)
{
	const double value = 5;
	ASSERT_EQ(factor * std::pow(value, power), m.compute({{variable, value}}));
}

TEST_F(TestMonomialPowerOfTwo, Display)
{
    std::ostringstream ss;
    m.display(ss);
    ASSERT_EQ("10x^2", ss.str());
}
