// AOJ 1379 Parallel Lines
// 2018.3.9 bal4u

#include <stdio.h>

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	if (c == '-') {
		c = getchar_unlocked();
		do n = 10*n + (c & 0xf), c = getchar_unlocked();
		while (c >= '0');
		return -n;
	}
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int gcd(int a, int b)
{
	int r;
	while (b != 0) r = a % b, a = b, b = r;
	return a;
}

#define BASE 2000
#define SFT  12		// 2^12 = 4096
int slope[16][16];
int x[16], y[16];
int dp[1<<16];

int main()
{
	int m, i, j, lim, s, a, b, f;
	int dx, dy;

	m = in(), lim = 1 << m;
	for (i = 0; i < m; i++) x[i] = in(), y[i] = in();

	for (i = 0; i < m; i++) for (j = i+1; j < m; j++) {
		dx = x[i] - x[j], dy = y[i] - y[j];
		if (dx < 0) dx = -dx, dy = -dy;
		if (!dx) dy = 1;
		else if (!dy) dx = 1;
		else {
			a = gcd(dx, dy); if (a < 0) a = -a;
			if (a > 1) dx /= a, dy /= a;
		}
		slope[i][j] = ((dx+BASE) << SFT) | (dy+BASE);
	}

	for (s = 0; s < lim; s++) {
		for (i = 0; i < m; i++) if ((1 << i) & s) {
			for (j = i+1; j < m; j++) if ((1 << j) & s) {
				f = 0;
				for (a = 0; a < m; a++) if ((1 << a) & s) {
					for (b = a+1; b < m; b++) if ((1 << b) & s) {
						if (slope[i][j] == slope[a][b]) f++;
					}
				}
				f = (f*(f-1)) >> 1;
				if (dp[s] < f) dp[s] = f;
			}
		}
	}

	for (s = 0; s < lim; s++) for (i = s; i; i = i-1 & s) {
		if (dp[s] < (f = dp[i]+dp[i^s])) dp[s] = f;
	}
	printf("%d\n", dp[lim-1]);
	return 0;
}

