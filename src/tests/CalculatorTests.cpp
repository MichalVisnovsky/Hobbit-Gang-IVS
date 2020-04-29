//============================================================================//
/**
 * @file CalculatorTests.cpp
 * @author TEREZA BURIANOVA
 * @date 03.04.2020
 * 
 * @brief Tests for the Hobbit Calculator math library.
 * @brief FIT VUT - IVS project 2
 */
//============================================================================//

#include "gtest/gtest.h"
#include "../lib.h"
#include <cmath>

using namespace MathFuncs;
typedef OurMathFuncs math;

//========== double Add(double a, double b); ==========//
/**
* @class CalculatorTests
* @brief A class of tests designed to test the Add function from the math library lib.h
*/
TEST(CalculatorTests, AddTest) {
    EXPECT_EQ(0, math::Add(-50, 50));
    EXPECT_EQ(-2000, math::Add(-500, -1500));
    EXPECT_EQ(1000000, math::Add(500000, 500000));
    EXPECT_FLOAT_EQ(0.328745, math::Add(-1, 1.328745));
    EXPECT_EQ(0, math::Add(0, 0));

    EXPECT_NE(5, math::Add(10, 5));
    EXPECT_NE(0.328745, math::Add(-1, 1.328745568));
    EXPECT_NE(1, math::Add(0.5, 0.4));
    EXPECT_NE(1000000, math::Add(500000, 1000000));
}

//========== double Subtract(double a, double b); ==========//
/**
* @class CalculatorTests
* @brief A class of tests designed to test the Subtract function from the math library lib.h
*/
TEST(CalculatorTests, SubtractTest) {
    EXPECT_EQ(0, math::Subtract(50, 50));
    EXPECT_EQ(-2000, math::Subtract(-1000, 1000));
    EXPECT_EQ(1000000, math::Subtract(2000000, 1000000));
    EXPECT_FLOAT_EQ(0.000001, math::Subtract(1.328746, 1.328745));
    EXPECT_EQ(0, math::Subtract(0, 0));

    EXPECT_NE(5, math::Subtract(10, 3));
    EXPECT_NE(0, math::Subtract(1, 1.328745568));
    EXPECT_NE(0, math::Subtract(0.5, 0.49999999));
    EXPECT_NE(500000, math::Subtract(1000000, 2000000));
}

//========== double Multiply(double a, double b); ==========//
/**
* @class CalculatorTests
* @brief A class of tests designed to test the Multiply function from the math library lib.h
*/
TEST(CalculatorTests, MultiplyTest) {
    EXPECT_EQ(0, math::Multiply(0, 0));
    EXPECT_EQ(2000, math::Multiply(2, 1000));
    EXPECT_EQ(1000000000000, math::Multiply(1000000, 1000000));
    EXPECT_FLOAT_EQ(1.76556460377, math::Multiply(1.328746, 1.328745));
    EXPECT_EQ(4, math::Multiply(2, 2));

    EXPECT_NE(5, math::Multiply(10, 3));
    EXPECT_NE(1, math::Multiply(1, 1.328745568));
    EXPECT_NE(0.5, math::Multiply(0.5, 0.5));
    EXPECT_NE(500000, math::Multiply(1000000, 2000000));
}

//========== double Divide(double a, double b); ==========//
/**
* @class CalculatorTests
* @brief A class of tests designed to test the Divide function from the math library lib.h
*/
TEST(CalculatorTests, DivideTest) {
    EXPECT_EQ(2, math::Divide(6, 3));
    EXPECT_EQ(2000, math::Divide(4000, 2));
    EXPECT_EQ(-100000, math::Divide(-1000000, 10));
    EXPECT_FLOAT_EQ(-1.00000075259, math::Divide(1.328746, -1.328745));
    EXPECT_FLOAT_EQ(1.51007222176, math::Divide(-68.4555, -45.3326));
    EXPECT_EQ(0, math::Divide(0, -5));

    EXPECT_NE(5, math::Divide(10, 5));
    EXPECT_NE(0.85, math::Divide(1, 1.328745568));
    EXPECT_NE(0.1, math::Divide(0.5, 0.5));
    EXPECT_NE(500000, math::Divide(1000000, 2000000));

    // Division by zero
    EXPECT_ANY_THROW(math::Divide(5, 0));
    EXPECT_ANY_THROW(math::Divide(-1000, 0));
}

//========== double Factorial(double a); ==========//
/**
* @class CalculatorTests
* @brief A class of tests designed to test the Factorial function from the math library lib.h
*/
TEST(CalculatorTests, FactorialTest) {
    EXPECT_EQ(2, math::Factorial(2));
    EXPECT_EQ(720, math::Factorial(6));
    EXPECT_EQ(1, math::Factorial(0));

    EXPECT_NE(0, math::Factorial(0));
    EXPECT_NE(1.551121, math::Factorial(25));
    EXPECT_NE(6, math::Factorial(6));

    // Negative and decimal values
    EXPECT_ANY_THROW(math::Factorial(-6));
    EXPECT_ANY_THROW(math::Factorial(2.387));
}

//========== float exp(float tmp1, int ex); ==========//
/**
* @class CalculatorTests
* @brief A class of tests designed to test the Exponent function from the math library lib.h
*/
TEST(CalculatorTests, ExponentTest) {
    EXPECT_EQ(4, math::Exponent(2, 2));
    EXPECT_EQ(-8, math::Exponent(-2, 3));
    EXPECT_EQ(1000000000, math::Exponent(1000, 3));
    EXPECT_EQ(1, math::Exponent(2, 0));
    EXPECT_EQ(8, math::Exponent(8, 1));
    EXPECT_EQ(0, math::Exponent(0, 1));
    EXPECT_FLOAT_EQ(378.890468382, math::Exponent(2.69, 6));

    EXPECT_NE(2, math::Exponent(2, 2));
    EXPECT_NE(1.551121, math::Exponent(25, 6));
    EXPECT_NE(0, math::Exponent(6, 6));

    // Negative and decimal values for exponents
    EXPECT_ANY_THROW(math::Exponent(-6, -2));
    EXPECT_ANY_THROW(math::Exponent(2, 1.36));
}

//========== float root(float tmp1, int ex); ==========//
/**
* @class CalculatorTests
* @brief A class of tests designed to test the Root function from the math library lib.h
*/
TEST(CalculatorTests, RootTest) {
    EXPECT_EQ(2, math::Root(4, 2));
    EXPECT_FLOAT_EQ(2, math::Root(16, 4));
    EXPECT_FLOAT_EQ(31622.7766017, math::Root(1000000000, 2));
    EXPECT_EQ(0, math::Root(0, 2));
    EXPECT_EQ(10, math::Root(10, 1));

    EXPECT_NE(2, math::Root(2, 2));
    EXPECT_NE(1.551121, math::Root(25, 1));
    EXPECT_NE(1, math::Root(0, 1));

    EXPECT_ANY_THROW(math::Root(4, 0));
    EXPECT_ANY_THROW(math::Root(-6, 2));
    EXPECT_ANY_THROW(math::Root(8, 2.1));
}

//========== float root(float tmp1, int ex); ==========//
/**
* @class CalculatorTests
* @brief A class of tests designed to test the Logarithm function from the math library lib.h
*/
TEST(CalculatorTests, LogarithmTest) {
    EXPECT_FLOAT_EQ(0.3010299, math::Logarithm(2));
    EXPECT_FLOAT_EQ(1.2041199, math::Logarithm(16));
    EXPECT_FLOAT_EQ(2, math::Logarithm(100));
    EXPECT_EQ(1, math::Logarithm(10));

    EXPECT_NE(2, math::Logarithm(2));
    EXPECT_NE(1.551121, math::Logarithm(25));

    EXPECT_ANY_THROW(math::Logarithm(0));
    EXPECT_ANY_THROW(math::Logarithm(-6));
}

//========== RUN ALL TESTS ==========//
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/**
* @endif
*/
