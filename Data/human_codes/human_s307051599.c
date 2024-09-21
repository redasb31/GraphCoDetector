#include <stdio.h>

#define INF 1145141919

int ai[1005];
int bi[1005];
int c[1005][15];
int dp[(1 << 12) + 5][1005];
//int dp2[(1 << 12) + 5][1005];

int min(int a, int b) {
	if (a < b) { return a; }
	else { return b; }
}

int main() {

	int N, M;

	scanf("%d %d",&N,&M);

	int i, j, k;

	for (i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ai[i] = a;
		bi[i] = b;
		for (j = 0; j < b; j++) {
			scanf(" %d", &c[i][j]);
		}
	}

	for (i = 0; i < (1 << 12); i++) {
		for (j = 0; j <= M; j++) {
			dp[i][j] = INF;
			//dp2[i][j] = INF;
		}
	}
	for (i = 0; i <= M; i++) {
		dp[0][i] = 0;
		//dp2[0][i] = 0;
	}

	for (i = M - 1; i >= 0; i--) {
		for (j = 0; j < (1 << N); j++) {
			int x = 0;
			for (k = 0; k < bi[i]; k++) {
				x |= (1 << (c[i][k] - 1));
			}
			dp[j | x][i] = min(dp[j | x][i + 1], min(dp[j][i + 1] + ai[i], dp[j | x][i]));
		}
	}

	/*

	for (i = M - 1; i >= 0; i--) {
		for (j = 0; j < (1 << N); j++) {
			int x = 0;
			for (k = 0; k < bi[i]; k++) {
				x |= (1 << (c[i][k] - 1));
			}
			dp2[j | x][i] = min(dp2[j][i + 1] + ai[i], dp2[j | x][i]);
			int y = INF;
			for (k = i; k >= 0; k--) {
				y = min(y, dp2[j | x][k]);
			}
			for (k = 0; k <= i; k++) {
				dp2[j | x][k] = y;
			}
		}
	}
	*/

	int ans = INF;

	for (i = 0; i <= M; i++) {
		if (ans > dp[(1 << N) - 1][i]) {
			ans = dp[(1 << N) - 1][i];
		}
	}

	if (ans == INF) { printf("-1\n"); }
	else { printf("%d\n",ans); }

	/*

	for (i = 0; i < (1<<N); i++) {
		for (j = 0; j <= M; j++) {
			printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
			printf("dp2[%d][%d]=%d\n", i, j, dp2[i][j]);
		}
	}
	*/

	return 0;
}