// Aizu 2824: Coastline
// 2017.9.23 bal4u@uu

#include <stdio.h>

int a[100000], size;

int main()
{
	int t, d, l;
	int x, i, ans;

	while (scanf("%d%d%d", &t, &d, &l) && t > 0) {
		size = 0;
		for (i = 0; i < t; i++) {
			scanf("%d", &x);
			if (x >= l) a[size++] = i;
		}
		t--, ans = 0;
		for (i = 1; i < size; i++) {
			x = d;
			if (a[i-1] + d > t) x = t - a[i-1];
			if (a[i] < a[i-1] + x) ans += a[i] - a[i-1];
			else ans += x;
		}
		if (size > 0) {
			ans += (a[size-1] + d > t) ? t - a[size-1] : d;
		}
		printf("%d\n", ans);
	}
	return 0;
}