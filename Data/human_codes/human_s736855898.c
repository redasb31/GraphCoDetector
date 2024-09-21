// AOJ 1204: Pipeline Scheduling
// 2017.12.4 bal4u@uu

#include <stdio.h>
#include <string.h>

int a[22];
int n, f;

int calc(int s, int k)
{
	int i, t, ans;

	if (k == 10) return n;
	ans = 0x7fffff;
	for (i = 1; i < n; i++) {
		if (!((s >> i) & 1)) {
			t = calc((s >> i) | f, k+1) + i;
			if (t < ans) ans = t;
		}
	}
	return ans;
}


int main()
{
	int i, j;
	char buf[22];

	while (scanf("%d", &n) && n > 0) {
		memset(a, 0, sizeof(a));
		for (i = 0; i < 5; i++) {
			scanf("%s", buf);
			for (j = 0; j < n; j++) {
				if (buf[j] == 'X') a[j] = i;
			}
		}
		f = 0;
		for (i = 1; i < n; i++) for (j = 0; j < i; j++) {
			if (a[i] == a[j]) f |= 1 << (i-j);
		}
		printf("%d\n", calc(f, 1));
	}
	return 0;
}