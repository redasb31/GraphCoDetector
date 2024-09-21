// AOJ 1522: Planarian Regeneration
// 2019.2.25 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c[42][42];
long double a[42][42], s[42][42];

long double calc(int m, int n, int x)
{
	int i, j;
	long double ans;

	memset(c, 0, sizeof(c)), memset(a, 0, sizeof(a)), memset(s, 0, sizeof(s));
	c[0][0] = 1, s[0][0] = 1.0;
	for (i = 0; i < 42; i++) a[0][i] = 1.0;
	for (i = 1; i <= x; i++) {
		for (j = 0; j < i; j++) {
			c[i][j]   += c[i-1][j];
			c[i][j+1] += c[i-1][j];
		}
		for (j = 0; j <= x; j++) {
			if (j < i) a[i][j] = a[i-1][j] * (long double)m/(m+n);
			else       a[i][j] = a[i-1][j] * (long double)n/(m+n);
		}
		for (j = 0; j < i; j++) {
			s[i][j] += s[i-1][j];
			s[i][j+1] += s[i-1][j] - a[i][j] * (long double)c[i-1][j];
		}
	}
	ans = 0; for (i = 0; i <= x; i++) ans += s[x][i]*a[x][i];
	return ans;
}

int main()
{
	int m, n, x, k, l, y;
	scanf("%d%d%d%d%d%d", &m, &n, &x, &k, &l, &y);
	printf("%.12Lf\n", calc(m, n, x)*calc(k, l, y));
	return 0;
}
