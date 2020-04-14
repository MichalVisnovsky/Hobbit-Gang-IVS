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
        static double Exponent(double a, double ex);

        //Returns ex root of a
        static double Root(double a, double ex);
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

    if(a!=(int)a)
    {
        throw "Number must be integer";
    }


    for(int i=1;i<=a;i++)
    {
      result = result * i;
    }
    return result;
}

double Exponent(double a, double ex){
    if (ex < 0)
    {
        throw "Negative number condition!";
    }

    if(ex!=(int)ex)
    {
        throw "Number must be integer";
    }

    double result = 1;
    for(double i = ex; i >= 1; i--)
    {
        result *= a;
    }
    return result;
}

double Root(double a, double ex){
    if (a < 0 || ex < 0)
    {
        throw "Negative number condition!";
    }

    if(ex!=(int)ex)
    {
        throw "Number must be integer";
    }

    double result;
    double dx;
    double eps = 10e-6;
    result = a * 0.5;
    dx = (a/Exponent(result,ex-1)-result)/ex;
    while(dx >= eps || dx <= -eps){
        result = result + dx;
        dx = (a/Exponent(result,ex-1)-result)/ex;
    }
return result;
}
#endif
