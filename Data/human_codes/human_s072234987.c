// AOJ 1593: Star
// 2017.11.29 bal4u@uu

#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795

// area = n*r^2*sin(180/n)*cos(180k/n)*sec(180(k-1)/n), for n/k star
int main()
{
	int n, k;

	scanf("%d%d", &n, &k);
	printf("%.10lf\n", n*sin(PI/n)*cos(k*PI/n)/cos((k-1)*PI/n));
	return 0;
}