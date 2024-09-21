// AOJ 2793 Lost Graph
// 2018.4.18 bal4u

#include <stdio.h>
#include <string.h>

/*******************************************/
/* Dinic's Max Flow Algorithm 
/*******************************************/

#define INF 0x01010101
#define VMAX 105
typedef struct { int to; int cap; int rev; } EDGE;
EDGE edge[VMAX][VMAX]; int hi[VMAX];
int V;				// 頂点数
int level[VMAX], iter[VMAX];
int queue[2*VMAX], qtop;

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

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int  a[52], b[52], sa, sb;
int  fr[102], fsz;
int  to[102], tsz;
char ans[52][52];

int main()
{
	int n, i, j;
	int source, sink;

	n = in();
	for (i = 0; i <= n; i++) a[i] = in();
	for (i = 0; i <= n; i++) b[i] = in();

	for (i = 0; i <= n; i++) {
		for (j = 0; j < a[i]; j++) fr[fsz++] = i, sa += i;
		for (j = 0; j < b[i]; j++) to[tsz++] = i, sb += i;
	}
	if (fsz != n || tsz != n || sa != sb) { puts("NO"); return 0; }

	source = n<<1, sink = source+1, V = sink+1;
	for (i = 0; i < n; i++) {
		add_edge(source, i, to[i]);
		for (j = 0; j < n; j++) add_edge(i, n+j, 1);
		add_edge(n+i, sink, fr[i]);
	}
	if (maxFlow(source, sink) < sb) { puts("NO"); return 0; }

	memset(ans, '0', sizeof(ans));
	for (i = 0; i < n; i++) for (j = 0; j < hi[i]; j++) {
		EDGE *ep = &edge[i][j];
		if (ep->to >= n && ep->to < source && ep->cap == 0) ans[i][ep->to - n] = '1';
	}
	puts("YES");
	for (i = 0; i < n; i++) {
		putchar(ans[i][0]);
		for (j = 1; j < n; j++) putchar(' '), putchar(ans[i][j]);
		putchar('\n');
	}
	return 0;
}
