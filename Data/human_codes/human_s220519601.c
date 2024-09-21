// Aizu 1163: Cards
// 2017.9.15 bal4u@uu

#include <stdio.h>
#include <string.h>

#define M 502
#define N 502

int m, n;
char graph[M][N], seen[N];
int matchL[M], matchR[N];

int b[M], r[N];

int gcd(int a, int b)
{
	int r;
	while (b != 0) r = a % b, a = b, b = r;
	return a;
}

int bpm(int u)
{
	int v;

	for (v = 0; v < n; v++) if (graph[u][v]) {
		if (seen[v]) continue;
		seen[v] = 1;
		if (matchR[v] < 0 || bpm(matchR[v])) {
			matchL[u] = v, matchR[v] = u;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int i, j, cnt;

	while (scanf("%d%d", &m, &n) && m) {
		for (i = 0; i < m; i++) scanf("%d", b+i);
		for (j = 0; j < n; j++) scanf("%d", r+j);
	    for (i = 0; i < m; i++) for (j = 0; j < n; j++) graph[i][j] = (gcd(b[i], r[j]) > 1);
		memset(matchL, -1, m*sizeof(matchL[0]));
		memset(matchR, -1, n*sizeof(matchR[0]));
		for (cnt = 0, i = 0; i < m; i++) { memset(seen, 0, n); if (bpm(i)) cnt++; }
		printf("%d\n", cnt);
	}
	return 0;
}