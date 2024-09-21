// AOJ 2076 Flame of Nucleus
// 2018.3.10 bal4u

#include <stdio.h>
#include <string.h>

/*******************************************/
/* Dinic's Max Flow Algorithm 
/*******************************************/

#define INF 0x01010101
#define VMAX 205
typedef struct { int to; int cap; int rev; } EDGE;
EDGE edge[VMAX][VMAX]; int hi[VMAX];
int V;				// 頂点数
int level[VMAX], iter[VMAX];
int queue[VMAX], qtop;

void add_edge(int from, int to, int cap)
{
	int f, t;
	EDGE *e;

	f = hi[from]++, t = hi[to]++;
	e = &edge[from][f], e->to = to, e->cap = cap, e->rev = t; 
	e = &edge[to][t], e->to = from, e->cap = 0, e->rev = f;
}

void bfs(int s)
{
	int i, v;
	EDGE *e;
	
	memset(level, -1, V << 2);
	level[s] = 0;
	queue[0] = s, qtop =1;
	while (qtop) {
		v = queue[--qtop];
		for (i = 0; i < hi[v]; i++) {
			e = &edge[v][i];
			if (e->cap > 0 && level[e->to] < 0) {
				level[e->to] = level[v] + 1;
				queue[qtop++] = e->to;
			}
		}
	}
}
 
int dfs(int v, int t, int f)
{
	int *i, d;
	EDGE *e;
	
	if (v == t) return f;
	for (i = &iter[v]; *i < hi[v]; (*i)++) {
		e = &edge[v][*i];
		if (e->cap > 0 && level[v] < level[e->to]) {
			d = dfs(e->to, t, f <= e->cap? f: e->cap);
			if (d > 0) {
				e->cap -= d;
				edge[e->to][e->rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
 
int maxFlow(int s, int t)
{
	int f, flow = 0;
	while (1) {
		bfs(s);
		if (level[t] < 0) break;
		memset(iter, 0, V << 2);
		while ((f = dfs(s, t, INF)) > 0) flow += f;
	}
	return flow;
}

/**********************************************/

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	if (c == EOF) return 0;
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int D[101][101];
int P[101];
int K[101];

int main()
{
	int N, M, L, i, j, k, a, b, d;
	int source, sink;

	while (N = in()) {
		M = in(), L = in();

		memset(D, INF, sizeof(D));
		for (i = 0; i < N; i++) D[i][i] = 0;
		for (i = 0; i < M; i++) {
			a = in()-1, b = in()-1, d = in();
			D[a][b] = D[b][a] = d;
		}
		for (k = 0; k < N; k++) {
			for (i = 0; i < N; i++) if (D[i][k] != INF) {
				for (j = 0; j < N; j++) if (D[k][j] != INF) {
					d = D[i][k] + D[k][j];
					if (D[i][j] > d) D[i][j] = d;
				}
			}
		}
		for (i = 0; i < N; i++) P[i] = in();
		for (i = 0; i < N; i++) K[i] = in();

		source = N << 1, sink = source+1, V = sink+1;
		memset(hi, 0, V << 2);

		for (i = 0; i < N; i++) {
			add_edge(source, i, P[i]);
			for (j = 0; j < N; j++) if (D[i][j] < L) add_edge(i, N+j, INF);
			add_edge(N+i, sink, K[i]);
		}
		
		printf("%d\n", maxFlow(source, sink));
	}
	return 0;
}
