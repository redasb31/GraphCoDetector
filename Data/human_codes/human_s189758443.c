#include <stdio.h>
#include <stdlib.h>

int main()
{
	int A, B, C, X, Y;
	scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
	
	int cost = A * X + B * Y, min = (X < Y)? X: Y;
	if (A + B > C * 2) cost -= ((A + B) - C * 2) * min;
	if (A > C * 2 && X > min) cost -= (A - C * 2) * (X - min);
	if (B > C * 2 && Y > min) cost -= (B - C * 2) * (Y - min);
	
	printf("%d\n", cost);
	fflush(stdout);
	return 0;
}