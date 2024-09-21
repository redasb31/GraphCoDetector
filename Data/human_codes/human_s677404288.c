// AOJ 2090: Repeated Subsequences
// 2017.10.9 bal4u@uu

#include <stdio.h>
#include <string.h>

char s[303], t[303];

int c[303][303]; char z[303];    // for LCS
char f[303][303];
int LCS(char *x, int m, char *y, int n)
{
	int i, j, ret, ret2;

	memset(c, 0, sizeof(c)); memset(f, 0, sizeof(f));
	for (i = 1; i <= m; i++) for (j = 1; j <= n; j++) {
		if (x[i-1] == y[j-1]) c[i][j] = c[i-1][j-1]+1, f[i][j] = 0;
		else {
			if (c[i-1][j] >= c[i][j-1]) c[i][j] = c[i-1][j], f[i][j] = 1;
			else                        c[i][j] = c[i][j-1], f[i][j] = -1;
		}
	}
	ret2 = ret = c[m][n]-1;
	while (ret >= 0) {
		if      (f[m][n] > 0) m--;
		else if (f[m][n] < 0) n--;
		else z[ret] = x[m-1], ret--, m--, n--;
	}
	z[ret2+1] = 0;
	return ret2+1;
}

int main()
{
	int n, m, ans, a;

	while (scanf("%s", s) && *s != '#') {
		n = strlen(s);
		for (m = n/2, ans = 0; m > ans; m--) {
			a = LCS(s, m, s+m, n-m);
			if (a > ans) { ans = a; memcpy(t, z, a+1); }
		}
		puts(t);
	}
	return 0;
}