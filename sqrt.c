#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	double input = atof(argv[1]);
	int flag=0;
	if(input < 0)
	{
		input*=-1;
		flag = 1;
	}
	union {
		double x;
		long long i;
	} bits;
	bits.x = input;
	bits.i = 0x1ff7a7dceaaec953 + (bits.i >> 1);
	bits.x -= (bits.x*bits.x - input)/(2*bits.x);
	bits.x -= (bits.x*bits.x - input)/(2*bits.x);
	bits.x -= (bits.x*bits.x - input)/(2*bits.x);
	if(flag)
	{
		printf("%.15fi\n",bits.x);
	}
	else
	{
		printf("%.15fi\n",bits.x);
	}
	return 0;
}
