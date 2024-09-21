#include <stdio.h>
#include <math.h>

int main(void)
{
	double a,s,l,b;
	scanf("%lf",&a);
	b=M_PI;
	l = 2*a*b;
	s = a*a*b;
	printf("%f %f",s,l);
	return 0;
}