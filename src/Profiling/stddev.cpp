/**
* @file stddev.cpp
* @author MICHAL VISNOVSKY (xvisno01)
*
* @date 13.04.2020
*
* @brief Program that counts standard deviation (stddev)
*/



#include <iostream>
#include <string>
#include <ctime>
#include <sys/poll.h>	
#include "../Calculator/lib.h"
#include "../Calculator/lib.cpp"
#define MAX 10000  //max numbers
using namespace std;

bool check_input(void);

int main (int argc, char *argv[]){

	int numcount = 0;
	double x_ = 0.0;
	double xi = 0.0;
	double s = 0.0;
	if(check_input())
	{
		char *num;
		while((fgets(num, MAX, stdin)) != NULL)
		{			
			double inum = strtod(num , NULL);
			x_ = OurMathFuncs::Add(x_ , inum);
			xi = OurMathFuncs::Add(xi , OurMathFuncs::Exponent(inum , 2));
			numcount++;
		}
	}
	else
	{	
		srand(time(NULL));
		for(int i = 0 ; i < 1000 ; i++)
		{			
			double inum = rand()% 1500 - 1; //generate random numbers
			x_ = OurMathFuncs::Add(x_ , inum);
			xi = OurMathFuncs::Add(xi , OurMathFuncs::Exponent(inum , 2));
			numcount++;
		}
	}
	s = OurMathFuncs::Root(OurMathFuncs::Divide(OurMathFuncs::Subtract(xi , OurMathFuncs::Multiply(OurMathFuncs::Exponent(OurMathFuncs::Divide(x_,numcount),2),numcount)),OurMathFuncs::Subtract(numcount, 1)), 2);
	cout << s << endl;
	return 0;
}

/**
* @brief Check if the file with numbers is given 
*
* @return 'true' if there is a file, 'false' if there is not
*/
bool check_input(void)
{
    struct pollfd fds;
    int ret;
    fds.fd = 0; 
    fds.events = POLLIN;
    ret = poll(&fds, 1, 0);
    if(ret == 1)
    	return true;
    else
        return false;
}

/**
* @endif
*/