// AOJ 1532 Yu-kun Likes Building Block
// 2018.3.18 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 高速数値入力
#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()  // 非負整数のみ
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}


// 2部グラフの最大マッチング
#define BMAX 105
int  hi[BMAX], to[BMAX][BMAX];
static char seen[BMAX];    // 内部作業用
static int  matchL[BMAX];  // 内部作業用
static int  matchR[BMAX];  // 内部作業用

int bpm(int u)
{
	int i, v;

	for (i = 0; i < hi[u]; i++) {
		v = to[u][i];
		if (seen[v]) continue;
		seen[v] = 1;
		if (matchR[v] < 0 || bpm(matchR[v])) {
			matchL[u] = v, matchR[v] = u;
			return 1;
		}
	}
	return 0;
}

int bipartiteMatching(int m, int n)
{
	int u, max;

	memset(matchL, -1, m * sizeof(int));
	memset(matchR, -1, n * sizeof(int));
	max = 0;
	for (u = 0; u < m; u++) {
		memset(seen, 0, n * sizeof(char));
		if (bpm(u)) max++;
	}
	return max;
}


// 本問題関連
#define MAX(a, b)  ((a)>=(b)? (a): (b))
#define MIN(a, b)  ((a)<=(b)? (a): (b))
typedef struct { int w, h; } T;
T t[105]; int N;

int main()
{
	int i, j;

	N = in();
	for (i = 0; i < N; i++)	t[i].w = in(), t[i].h = in();
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) if (i != j) {
		if (MAX(t[i].w, t[i].h) < MAX(t[j].w, t[j].h) &&
			MIN(t[i].w, t[i].h) < MIN(t[j].w, t[j].h))
			to[i][hi[i]++] = j;
	}
#if 0
	for (i = 0; i < N; i++) {
		printf("[%d] hi=%d:", i, hi[i]);
		for (j = 0; j < hi[i]; j++) printf(" %d", to[i][j]);
		printf("\n");
	}
#endif
	printf("%d\n", N - bipartiteMatching(N, N));
	return 0;
}
