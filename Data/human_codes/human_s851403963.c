#include<stdio.h>

int main(void) {
	int x, y, z, sum;
	scanf("%d %d", x, y);
	sum = x + y + 2;
	z = x%y;
	while (z != 0) {
		x = y;
		y = z;
		z = x%y;
	}
	sum -= (y + 1);
	printf("%d\n", sum);
	return 0;
}
