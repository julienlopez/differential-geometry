#include "expression/functions/cosine.hpp"
#include "expression/functions/sine.hpp"
#include "expression/monomial.hpp"
#include "expression/scalar.hpp"

#include <gtest/gtest.h>

#include <cmath>

struct TestSineOfScalar : public ::testing::Test
{
    const Sine s = {std::make_unique<Scalar>(10)};
};

TEST_F(TestSineOfScalar, ComputeValue)
{
    ASSERT_EQ(std::sin(10), s.compute({}));
}

TEST_F(TestSineOfScalar, VariableList)
{
    ASSERT_EQ(0, s.variableCount());
    ASSERT_TRUE(s.variableList().empty());
}

TEST_F(TestSineOfScalar, Display)
{
    std::ostringstream ss;
    s.display(ss);
    ASSERT_EQ("sin(10)", ss.str());
}

struct TestSineOfMonomial : public ::testing::Test
{
    const Variable var {"t"};
    const Sine s {std::make_unique<Monomial>(var, 10)};
};

TEST_F(TestSineOfMonomial, ComputeValue)
{
    ASSERT_EQ(std::sin(10*5), s.compute({{var, 5}}));
}

TEST_F(TestSineOfMonomial, VariableList)
{
    ASSERT_EQ(1, s.variableCount());
    ASSERT_EQ(var, *s.variableList().begin());
}

TEST_F(TestSineOfMonomial, Display)
{
    std::ostringstream ss;
    s.display(ss);
    ASSERT_EQ("sin(10t)", ss.str());
}

struct TestCosineOfScalar : public ::testing::Test
{
    const Cosine c = {std::make_unique<Scalar>(10)};
};

TEST_F(TestCosineOfScalar, ComputeValue)
{
    ASSERT_EQ(std::cos(10), c.compute({}));
}

TEST_F(TestCosineOfScalar, VariableList)
{
    ASSERT_EQ(0, c.variableCount());
    ASSERT_TRUE(c.variableList().empty());
}

TEST_F(TestCosineOfScalar, Display)
{
    std::ostringstream ss;
    c.display(ss);
    ASSERT_EQ("cos(10)", ss.str());
}

TEST_F(TestCosineOfScalar, Derivative)
{
    const auto d = c.derivative(Variable("a"));
    std::ostringstream ss;
    d->display(ss);
    ASSERT_EQ("0", ss.str());
}

struct TestCosineOfMonomial : public ::testing::Test
{
    const Variable var {"t"};
    const Cosine c {std::make_unique<Monomial>(var, 10)};
};

TEST_F(TestCosineOfMonomial, ComputeValue)
{
    ASSERT_EQ(std::cos(10*5), c.compute({{var, 5}}));
}

TEST_F(TestCosineOfMonomial, VariableList)
{
    ASSERT_EQ(1, c.variableCount());
    ASSERT_EQ(var, *c.variableList().begin());
}

TEST_F(TestCosineOfMonomial, Display)
{
    std::ostringstream ss;
    c.display(ss);
    ASSERT_EQ("cos(10t)", ss.str());
}

TEST_F(TestCosineOfMonomial, DerivativeSameVariable)
{
    const auto d = c.derivative(var);
    std::ostringstream ss;
    d->display(ss);
    ASSERT_EQ("10 * sin(10t)", ss.str());
}

TEST_F(TestCosineOfMonomial, DerivativeOtherVariable)
{
    const auto d = c.derivative(Variable("a"));
    std::ostringstream ss;
    d->display(ss);
    ASSERT_EQ("0", ss.str());
}