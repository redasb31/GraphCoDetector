#include <stdio.h>

int main(void) {
	int k, n, x = 0;
	int a[100010] = {};

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		a[k]++;
		a[k + 1]++;
		a[k + 2]++;
	}

	for (int i = 0; i < 100010; i++)
	{
		x = (a[i] > a[x]) ? i : x;
	}
	printf("%d\n", a[x]);

	return 0;
}