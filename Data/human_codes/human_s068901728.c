// AOJ 2026: Divisor is the Conqueror
// 2017.11.03 bal4u@uu

#include <stdio.h>
#include <string.h>

int c[15];
int ans[54];
char f[14][365];		// 364=(13+1)*13/2*4

int rec(int j, int k)
{
	int i;
	if (j < 0) return 0;
	for (i = 1; i <= 13; i++) {
		if (!c[i]) continue;
		if (f[i][k-i]) {
			c[i]--, ans[j] = i;
			if (!rec(j-1, k-i)) return 0;
			c[i]++;
		}
	}
	return 1;
}

int main()
{
	int n, i, v, s;

	memset(f[1], 1, sizeof(f[1]));
	for (i = 2; i <= 13; i++) {
		f[i][0] = 1;
		for (v = i; v < 365; v += i) f[i][v] = 1;
	}

	while (scanf("%d", &n) && n > 0) {
		memset(c, 0, sizeof(c));
		for (s = 0, i = 0; i < n; i++) {
			scanf("%d", &v);
			s += v, c[v]++;
		}
		memset(ans, 0, sizeof(ans));
		if (rec(n-1, s)) puts("No");
		else {
			printf("%d", ans[0]);
			for (i = 1; i < n; i++) printf(" %d", ans[i]);
			putchar('\n');
		}
	}
	return 0;
}