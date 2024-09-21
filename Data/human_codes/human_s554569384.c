// AOJ 2920: Tea Party
// 2019.2.17 bal4u

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, a, sum, min;

	scanf("%d", &N);
	sum = 0, min = 101;
	while (N--) {
		scanf("%d", &a);
		sum += a;
		if ((a & 1) && a < min) min = a;
	}
	if (sum & 1) sum -= min;
	printf("%d\n", sum / 2);
	return 0;
}

