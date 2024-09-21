#include <stdio.h>

#define N	70
#define M	70
#define MD	1000000007

int min(int a, int b) { return a < b ? a : b; }

int ch[N + 1][N + 1], cnt[N + 1][N + 1];

void init() {
	int n, b, k, l;

	ch[0][0] = 1;
	for (n = 1; n <= N; n++) {
		ch[n][0] = 1;
		for (k = 1; k <= n; k++)
			ch[n][k] = (ch[n - 1][k] + ch[n - 1][k - 1]) % MD;
	}
	for (n = 1; n <= N; n++) {
		cnt[n][0] = 1;
		for (b = 1; b <= (n + 1) / 2; b++)
			for (l = b; l <= n; l++)
				cnt[n][b] = (cnt[n][b] + (long long) ch[l - 1][b - 1] * ch[n - l + 1][b]) % MD;
	}
}

int main() {
	static char cc[M + 1];
	static int iir[M + 1], iib[M + 1], dp[N + 1][M + 1][M + 1], pp[M];
	int n, m, mr, mb, c, h, i, j, k, i_, j_, k_, b, l, ans;

	init();
	scanf("%d%d%s", &n, &m, cc);
	mr = mb = 0, k = 0;
	for (i = 0; i < m; i++)
		if (cc[i] == 'r')
			iir[mr++] = i, k++;
		else if (k > 0)
			iib[mb++] = i, k--;
	ans = 1;
	for (c = 1; c <= (n + 1) / 2 && c <= mr; c++) {
		for (i = 0; i < m; i++)
			pp[i] = 1;
		for (h = 0; h < c; h++)
			pp[iir[h]] = 0;
		for (i = m - 2; i >= 0; i--)
			pp[i] += pp[i + 1];
		for (i = 0; i <= n - c + 1; i++)
			for (j = 0; j <= c && j <= i; j++)
				for (k = 0; k <= m && k <= i / 2 + j; k++)
					dp[i][j][k] = 0;
		dp[0][0][0] = 1;
		for (b = 0; b <= m; b++)
			for (l = b == 0 ? 1 : b * 2 - 1; l <= n - c + 1; l++) {
				int y = cnt[l][b];

				for (i = n - c + 1 - l; i >= 0; i--)
					for (j = min(c - 1, i); j >= 0; j--)
						for (k = min(m - b, i / 2 + j); k >= 0; k--) {
							int x = dp[i][j][k], p;

							if (x == 0)
								continue;
							p = 1;
							for (h = 1; (i_ = i + h * l) <= n - c + 1 && (j_ = j + h) <= c && (k_ = k + h * b) <= m; h++) {
								if (b > 0 && (c - j_ >= mb || pp[iib[c - j_]] < k_))
									break;
								p = (long long) p * y % MD;
								dp[i_][j_][k_] = (dp[i_][j_][k_] + (long long) x * p % MD * ch[j_][h]) % MD;
							}
						}
			}
		j = c;
		for (i = 0; i <= n - c + 1; i++)
			for (k = 0; k <= m && k <= i / 2 + j; k++)
				ans = (ans + (long long) dp[i][j][k] * ch[n - i + 1][j]) % MD;
	}
	printf("%d\n", ans);
	return 0;
}
