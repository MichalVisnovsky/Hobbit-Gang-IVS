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
double Add(double a, double b){
    double result = a + b;
    return result;
}

double Subtract(double a, double b){
    double result = a - b;
    return result;
}

double Multiply(double a, double b){
    double result = a * b;
    return result;
}

double Divide(double a, double b){
    if (b == 0)
    {
         throw "Division by zero condition!";
    }
    double result = a / b;
    return result;
}

double Factorial(double a){
    double result = 1;

    if (a < 0)
    {
        throw "Negative number condition!";
    }


    for(int i=1;i<=a;i++)
    {
      result = result * i;
    }
    return result;
}



#endif
