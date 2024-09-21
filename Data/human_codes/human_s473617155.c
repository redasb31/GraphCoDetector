// AOJ 2806: Weight Range
// 2017.10.10 bal4u@uu

#include <stdio.h>
#include <string.h>

int a[2005];

int gcd(int a, int b)
{
	int r;
	while (b != 0) r = a % b, a = b, b = r;
	return a;
}

int main()
{
	int n, m, i, j, k, group, step, min, max, ans;

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", a+i);
	memcpy(a+n, a, sizeof(int)*n);

	step = gcd(n, m);
	group = n /step;   // = lcm(n,m)/m = (m*n/gcd(n,m))/m = n/gcd(n,m)

	ans = 0;
	for (k = 0, i = 0; i < group; i++, k += step) {
		min = max = a[k];
		for (j = 1; j < m; j++) {
			if      (a[k+j] < min) min = a[k+j];
			else if (a[k+j] > max) max = a[k+j];
		}
		ans += max-min;
	}
	printf("%d\n", ans);
	return 0;
}