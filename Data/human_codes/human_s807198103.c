#include <stdio.h>
int main(void)
{
	long max = -1000000;
	long min = 1000000;
	long sum = 0;
	int n, a;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		if (max < a) {
			max = a;
		}

		if (min > a) {
			min = a;
		}

		sum += a;
	}

		printf("%d %d %d", min, max, sum);

		return 0;

}