// AOJ 2117 Connect Line Segments
// 2018.3.18 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { double x, y; } PP;

#define INF 1e16
int N;
PP pp[14][2];
double dis[14][2][14][2];
double dp[1 << 14][14][2];

double dist(PP p1, PP p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

double travellingSalesman(int n)
{
	int s, v, i, j, k, m, max;
	double x, ans;

	max = 1 << n;
	for (s = 0; s < max; s++) for (v = 0; v < n; v++) for (i = 0; i < 2; i++) dp[s][v][i] = INF;
	for (v = 0; v < n; v++) for (i = 0; i < 2; i++) dp[1 << v][v][i] = 0;

	for (s = 0; s < max; s++) for (v = 0; v < n; v++) if ((s >> v) & 1) {
		for (i = 0; i < 2; i++) {
			for (j = 0; j < n; j++) {
				if ((s >> j) & 1) continue;
				for (k = 0; k < 2; k++) {
					m = s | (1 << j);
					x = dp[s][v][i] + dis[v][i][j][k];
					if (dp[m][j][!k] > x) dp[m][j][!k] = x;
				}
			}
		}
	}
	ans = INF;
	for (v = 0; v < n; v++) for (i = 0; i < 2; i++) {
		if (ans > dp[max - 1][v][i]) ans = dp[max - 1][v][i];
	}
	return ans;
}

int main()
{
	int cno, i, j;
	double ans;

	cno = 0;
	while (scanf("%d", &N) && N) {
		for (i = 0; i < N; i++) {
			scanf("%lf%lf%lf%lf", &pp[i][0].x, &pp[i][0].y, &pp[i][1].x, &pp[i][1].y);
		}
		ans = 0;
		for (i = 0; i < N; i++) {
			ans += dist(pp[i][0], pp[i][1]);
			for (j = i + 1; j < N; j++) {
				dis[i][0][j][0] = dis[j][0][i][0] = dist(pp[i][0], pp[j][0]);
				dis[i][0][j][1] = dis[j][1][i][0] = dist(pp[i][0], pp[j][1]);
				dis[i][1][j][0] = dis[j][0][i][1] = dist(pp[i][1], pp[j][0]);
				dis[i][1][j][1] = dis[j][1][i][1] = dist(pp[i][1], pp[j][1]);
			}
		}
		ans += travellingSalesman(N);
		printf("Case %d: %.8lf\n", ++cno, ans);
	}
	return 0;
}
