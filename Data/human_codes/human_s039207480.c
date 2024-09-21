// AOJ 0290: Microorganism Power Generation
// 2017.10.27 bal4u@uu

#include <stdio.h>
#include <string.h>

int bm[14], bw[14], m, w;
int tbl[14][14];
int dp[14][4100];

int main()
{
	int i, j, k, d, x, lim;

	while (scanf("%d%d", &m, &w) && m > 0) {
		for (i = 0; i < m; i++) scanf("%d", bm + i);
		for (j = 0; j < w; j++) scanf("%d", bw + j);

		memset(tbl, 0, sizeof(tbl));
		for (i = 0; i < m; i++) for (j = 0; j < w; j++) {
			d = bm[i] - bw[j]; if (d < 0) d = -d;
			x = d * (d - 30) * (d - 30);
			tbl[i][j] = x;
		}

		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		lim = 1 << w;
		for (i = 0; i < m; i++) {
			for (k = 0; k < lim; k++) if (dp[i][k] >= 0) {
				if (dp[i+1][k] < dp[i][k]) dp[i+1][k] = dp[i][k];
				for (j = 0; j < w; j++) {
					if (k & (1<<j)) continue;
					d = k | (1<<j);
					x = dp[i][k] + tbl[i][j];
					if (dp[i+1][d] < x) dp[i+1][d] = x;
				}
			}
		}

		for (x = 0, i = 0; i < lim; i++) if (dp[m][i] > x) x = dp[m][i];
		printf("%d\n", x);
	}
	return 0;
}