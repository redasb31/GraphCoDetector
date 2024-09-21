// AOJ 2917: Pray
// 2019.2.17 bal4u

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int h, w, x, y;

	scanf("%d%d%d%d", &h, &w, &x, &y);
	if ((h*w & 1) && ((x+y) & 1)) puts("No");
	else puts("Yes");
	return 0;
}

