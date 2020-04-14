#ifndef LIB_H
#define LIB_H

namespace MathFuncs
{
    class OurMathFuncs
    {
    public:
        // Returns a + b
        static double Add(double a, double b);

        // Returns a - b
        static double Subtract(double a, double b);

        // Returns a * b
        static double Multiply(double a, double b);

        // Returns a / b
        static double Divide(double a, double b);

        // Returns a!
        static double Factorial(double a);

        //Returns a^ex
        static double Exponent(double a, int ex);

        //Returns ex root of a
        static double Root(int ex, double a);
    };
}


#endif
