// AOJ 2891 Namo.. Cut
// 2019.3.22 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//// 高速数値入力
#if 1
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif
int in()
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

//// 閉路の検出
#define MAX_V 100002
int  *to[MAX_V], hi[MAX_V];
char cycle[MAX_V];            // 検出の結果

void dfs(int V)
{
	int i, j, f, node, par, next;
	static char used[MAX_V];
	static int path[MAX_V], sz;
	typedef struct { int node, par; } Q;
	static Q q[MAX_V*2]; int top;

	f = 0, sz = 0, top = 1;
	q[0].node = 1, q[0].par = 0;
	while (top) {
		node = q[--top].node, par = q[top].par;
		//		printf("top=%d, node=%d, par=%d, sz=%d\n", top, node, par, sz);
		if (node < 0) { sz--; continue; }
		used[node] = 1;
		path[sz++] = node;
		q[top++].node = -1;

		for (i = 0; i < hi[node]; i++) {
			next = to[node][i];
			if (next == par) continue;
			if (used[next] && !f) {
				f = 1;
				for (j = sz - 1; path[j] != next; j--) cycle[path[j]] = 1;
				cycle[path[j]] = 1;
			}
			else if (!used[next]) q[top].node = next, q[top++].par = node;
		}
	}
}

int main()
{
	int i, N, Q, u, v;
	int *memo, sz;

	// 入力受付。C言語ではややこしい
	N = in();
	memo = malloc(sizeof(int) * N * 2);
	sz = 0; for (i = 0; i < N; i++) {
		memo[sz++] = u = in(), memo[sz++] = v = in();
		hi[u]++, hi[v]++;
	}
	for (i = 1; i <= N; i++) {
		if (hi[i]) to[i] = malloc(sizeof(int) * hi[i]);
	}
	memset(hi, 0, sizeof(int) * (N + 1));
	i = 0; while (i < sz) {
		u = memo[i++], v = memo[i++];
		to[u][hi[u]++] = v, to[v][hi[v]++] = u;
	}

	dfs(N + 1);     // 閉路の検出 閉路上にある頂点 u --> cycle[u] == 1

	Q = in();
	while (Q--) {
		u = in(), v = in();
		pc((cycle[u] & cycle[v]) ? '2' : '1'), pc('\n');
	}
	return 0;
}
