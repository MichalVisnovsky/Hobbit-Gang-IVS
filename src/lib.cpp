//
// Created by tereza on 14.04.20.
//

#include "lib.h"
using namespace MathFuncs;

double OurMathFuncs::Add(double a, double b){
    double result = a + b;
    return result;
}

double OurMathFuncs::Subtract(double a, double b){
    double result = a - b;
    return result;
}

double OurMathFuncs::Multiply(double a, double b){
    double result = a * b;
    return result;
}

double OurMathFuncs::Divide(double a, double b){
    if (b == 0)
    {
         throw "Division by zero condition!";
    }
    double result = a / b;
    return result;
}

double OurMathFuncs::Factorial(double a){
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

double OurMathFuncs::Exponent(double a, double ex){
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

double OurMathFuncs::Root(double a, double ex){
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
