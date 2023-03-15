#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	double input = atof(argv[1]);
	union {
		double x;
		long long i;
	} bits;
	bits.x = input;
	bits.i = 0x1ff7a7dceaaec953 + (bits.i >> 1);
	bits.x -= (bits.x*bits.x - input)/(2*bits.x);
	bits.x -= (bits.x*bits.x - input)/(2*bits.x);
	bits.x -= (bits.x*bits.x - input)/(2*bits.x);
	printf("%.15f\n",bits.x);
}
