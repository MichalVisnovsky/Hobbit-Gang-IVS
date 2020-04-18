/**
*   @mainpage Hobbit Gang Calculator
*   @author BORIS BOBOCKÝ, MICHAL VIŠNOVSKÝ
*   @date 04.16.2020
*
*   @link
*   lib.h
*   @endlink
*   @file lib.h
*   @brief mathematical library for calculator
*/


#ifndef LIB_H
#define LIB_H


namespace MathFuncs
{
    /**
    *   @class mathematical functions
    */
    class OurMathFuncs
    {
    public:

        /**
        * @brief addition of numbers
        *
        * @param a - first given number, first addent
        * @param b - second given number, second addent
        *
        * @pre at least two numbers have to be given
        * @post two numbers are added together
        *
        * @return number - result of addition
        *
        */
        static double Add(double a, double b);


         /**
        * @brief subtraction of numbers
        *
        * @param a - first given number
        * @param b - second given number, which will be subtracted from parameter 'a'
        *
        * @pre at least two numbers have to be given
        * @post two numbers are subtracted
        *
        * @return number - result of subtraction
        *
        */
        static double Subtract(double a, double b);


         /**
        * @brief multiplication of numbers
        *
        * @param a - first given number, first multiplicant
        * @param b - second given number, seconf multiplicant
        *
        * @pre at least two numbers have to be given
        * @post two numbers are multiplied
        *
        * @return number - result of  multiplication
        *
        */
        static double Multiply(double a, double b);


         /**
        * @brief division of numbers
        *
        * @param a - first given number, first divident
        * @param b - second given number, second divident
        *
        * @pre at least two numbers have to be given, parameter 'b' should not be zero
        * @post two numbers are divided
        *
        * @return number - result of division
        *
        */
        static double Divide(double a, double b);


         /**
        * @brief enumeration of factorial of a number
        *
        * @param a - given number
        *
        * @pre at least one numbers has to be given
        * @post factorial of a number is enumerated
        *
        * @return number - enumeration result of factorial of a number
        *
        */
        static double Factorial(double a);


         /**
        * @brief exponent calculation of a number
        *
        * @param a - first given number, which will be raising to a power of parameter 'ex'
        * @param ex - second given number, exponent
        *
        * @pre two numbers have to be given
        * @post number 'a' is raised to power of 'ex'
        *
        * @return number - result of exponentiation
        *
        */
        static double Exponent(double a, double ex);


         /**
        * @brief extraction of a root
        *
        * @param a - first given number, radicand
        * @param ex - second given number, root
        *
        * @pre two numbers have to be given
        * @post root extracion of a number
        *
        * @return number - result of an 'ex' root of a number
        *
        */
        static double Root(double a, double ex);

        /**
       * @brief common logarithm
       *
       * @param x - exponent
       *
       * @pre one number has to be given
       * @post found y
       *
       * @return number - result of common logarithm of x
       *
       */
       static double Logarithm(double x);
    };
}

#endif
/**
* @}
*/
