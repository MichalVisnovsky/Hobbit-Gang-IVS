#include <iostream>
#include <string>
#include <ctime>
#include <sys/poll.h>	
#include "lib.h"
#define MAX 10000
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
			x_ = Add(x_ , inum);
			xi = Add(xi , Exponent(inum , 2));
			numcount++;
		}
	}
	else
	{
		srand(time(NULL));
		for(int i = 0 ; i < 100 ; i++)
		{			
			double inum = rand()% 1500 - 1;
			x_ = Add(x_ , inum);
			xi = Add(xi , Exponent(inum , 2));
			numcount++;
		}
	}
	s = Root(Divide(Subtract(xi , Multiply(Exponent(Divide(x_,numcount),2),numcount)),Subtract(numcount, 1)), 2);
	cout << s << endl;
	return 0;
}

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
