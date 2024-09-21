#include <stdio.h>

int main()
{
	long long c[7], t[5], N, min;
	int i;
	scanf("%lld", &N);
	for (i = 0; i < 5; i++)
		scanf("%lld", &t[i]);
	min = t[0];
	for (i = 1; i < 5; i++)
		if (min > t[i])
			min = t[i];

	printf("%lld\n", (N-1)/min + 5);
}