// AOJ 2429 Attack the Moles
// 2018.3.8 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QMAX 2000
typedef struct { int t, s; } QUE;
QUE que[QMAX]; int qsize;

#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)

void min_heapify(int i)
{
	int l, r, min;
	QUE qt;

	l = LEFT(i), r = RIGHT(i);
	if (l < qsize && que[l].t < que[i].t) min = l; else min = i;
	if (r < qsize && que[r].t < que[min].t) min = r;
	if (min != i) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		min_heapify(min);
	}
}

void deq()
{
	que[0] = que[--qsize];
	min_heapify(0);
}

void enq(int s, int t)
{
	int i, min;
	QUE qt;

	i = qsize++;
	que[i].s = s, que[i].t = t;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		i = min;
	}
}

#define INF 0x01010101
#define MAX 210
typedef struct { int to, rev; int cap, cost; } EDGE;
EDGE *edge[MAX]; int hi[MAX], lim[MAX];
int V;				// 頂点数
int potential[MAX], min_cost[MAX], prevv[MAX], preve[MAX];

void check_lim(int a)
{
	if (hi[a] < lim[a]) return;
	if (lim[a] == 0) {
		lim[a] = 4, hi[a] = 0;
		edge[a] = malloc(sizeof(EDGE) *lim[a]);
	} else if (hi[a] == lim[a]) {
		int k = lim[a];
		if (k > 512) k = 512;
		lim[a] += k;
		edge[a] = realloc(edge[a], sizeof(EDGE) *lim[a]);
	}
}

void add_edge(int from, int to, int cap, int cost)
{
	int f, t;
	EDGE *ep;

	check_lim(from), check_lim(to);
	f = hi[from]++, t = hi[to]++;
	ep = &edge[from][f], ep->to = to, ep->cap = cap, ep->cost = cost, ep->rev = t; 
	ep = &edge[to][t], ep->to = from, ep->cap = 0, ep->cost = -cost, ep->rev = f;
}

int minCostFlow(int S, int T, int F)
{
	int i, s, ns, t, nt, ret;
	EDGE *ep;

	ret = 0;
//	memset(potential, 0, V << 2);
  
	while (F > 0) {
		memset(min_cost, INF, V << 2);
		qsize = 0;
		enq(S, 0), min_cost[S] = 0;
  
		while (qsize) {
			s = que[0].s, t = que[0].t, deq();
			if (min_cost[s] < t) continue;

			for (i = 0; i < hi[s]; i++) {
				ep = &edge[s][i], ns = ep->to;
				nt = t + ep->cost + potential[s] - potential[ns];
				if(ep->cap > 0 && min_cost[ns] > nt) {
					min_cost[ns] = nt;
					prevv[ns] = s, preve[ns] = i;
					enq(ns, nt);
				}
			}
		}
		if (min_cost[T] == INF) return -1;
		for (s = 0; s < V; s++) potential[s] += min_cost[s];

		t = F;
		for (s = T; s != S; s = prevv[s]) {
			ep = &edge[prevv[s]][preve[s]];
			if (t > ep->cap) t = ep->cap;
		}
		F -= t;

		ret += t * potential[T];
		for (s = T; s != S; s = prevv[s]) {
			ep = &edge[prevv[s]][preve[s]];
			ep->cap -= t;
			edge[s][ep->rev].cap += t;
		}
	}
	return ret;
}

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
while (c <= ' ') c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int  W[105][105], E[105][105]; 
char F[105][105], G[105][105];
int  ans[10002][2];

int main()
{
	int n, r, c, s, i;
	int source, sink;
	EDGE *ep;

	n = in();
	for (r = 0; r < n; r++) for (c = 0; c < n; c++) W[r][c] = in();
	for (r = 0; r < n; r++) for (c = 0; c < n; c++) E[r][c] = in();
	s = 0; for (r = 0; r < n; r++) {
		fgets(F[r], 105, stdin);
		for (c = 0; c < n; c++) if (F[r][c] == 'o') s += E[r][c];
	}

	source = n+n, sink = source+1, V = sink+1;

	for (r = 0; r < n; r++) add_edge(source, r, 1, 0), add_edge(r+n, sink, 1, 0);
	for (r = 0; r < n; r++) for (c = 0; c < n; c++) {
		if (F[r][c] == 'o') add_edge(r, c+n, 1, -E[r][c]);
		else                add_edge(r, c+n, 1, W[r][c]);
	}
 
	printf("%d\n", minCostFlow(source, sink, n) + s);

	memset(G, '.', sizeof(G));
	for (r = 0; r < n; r++) {
		for (i = 0; i < hi[r]; i++) {
			ep = &edge[r][i];
			if (ep->cap == 0 && ep->to >= n && ep->to < 2*n) G[r][ep->to - n] = 'o';
		}
	}

	s = 0;
	for (r = 0; r < n; r++) for (c = 0; c < n; c++) {
		if (F[r][c] != G[r][c]) ans[s][0] = r, ans[s++][1] = c;
	}

	printf("%d\n", s);
	for (i = 0; i < s; i++) {
		r = ans[i][0], c = ans[i][1];
		if (F[r][c] == 'o') printf("%d %d erase\n", r+1, c+1);
		else                printf("%d %d write\n", r+1, c+1);
	}
	return 0;
}
 
