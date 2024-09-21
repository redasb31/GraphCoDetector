// AOJ 2828 Matryoshka Doll
// 2018.3.9 bal4u

#include <stdio.h>
#include <string.h>

#define QMAX 500
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

#define INF 0x10101010
#define MAX 205
typedef struct { int to, rev; int cap, cost; } EDGE;
EDGE edge[MAX][MAX]; int hi[MAX];
int V;				// 頂点数
int potential[MAX], dist[MAX], prevv[MAX], preve[MAX];

void add_edge(int from, int to, int cap, int cost)
{
	int f, t;
	EDGE *ep;

	f = hi[from]++, t = hi[to]++;
	ep = &edge[from][f], ep->to = to, ep->cap = cap, ep->cost = cost, ep->rev = t; 
	ep = &edge[to][t], ep->to = from, ep->cap = 0, ep->cost = -cost, ep->rev = f;
}

int minCostFlow(int S, int T, int F)
{
	int i, v, nv, t, nt, ret;
	EDGE *ep;

	ret = 0;
	memset(potential, 0, V << 2);
  
	while (F > 0) {
		memset(dist, INF, V << 2);
		qsize = 0;
		dist[S] = 0;
		enq(S, 0);
		while (qsize) {
			v = que[0].s, t = que[0].t, deq();
			if (dist[v] < t) continue;
			for (i = 0; i < hi[v]; i++) {
				ep = &edge[v][i];
				if (ep->cap <= 0) continue;
				nv = ep->to;
				nt = t + ep->cost - potential[nv] + potential[v];
				if(dist[nv] > nt) {
					dist[nv] = nt;
					prevv[nv] = v, preve[nv] = i;
					enq(nv, nt);
				}
			}
		}
		if (dist[T] == INF) return -1;
		for (v = 0; v < V; v++) potential[v] += dist[v];

		t = F;
		for (v = T; v != S; v = prevv[v]) {
			ep = &edge[prevv[v]][preve[v]];
			if (t > ep->cap) t = ep->cap;
		}
		F -= t;

		ret += t * potential[T];
		for (v = T; v != S; v = prevv[v]) {
			ep = &edge[prevv[v]][preve[v]];
			ep->cap -= t;
			edge[v][ep->rev].cap += t;
		}
	}
	return ret;
}

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

typedef struct { int x, y, z; } T;
T tbl[102];

int main()
{
	int N, i, j;
	int source, sink;

	while (N = in()) {
		source = N << 1, sink = source+1, V = sink+1;
		memset(hi, 0, V << 2);

		for (i = 0; i < N; i++) {
			int x = in(), y = in(), z = in(), t;
			if (y > z) t = y, y = z, z = t;
			if (x > y) t = x, x = y, y = t;
			if (y > z) t = y, y = z, z = t;
			tbl[i].x = x, tbl[i].y = y, tbl[i].z = z;
		}

		for (i = 0; i < N; i++) for (j = 0; j < N; j++) if (i != j) {
			if (tbl[i].x < tbl[j].x && tbl[i].y < tbl[j].y && tbl[i].z < tbl[j].z)
				add_edge(i, N+j, 1, 0);
		}
		for (i = 0; i < N; i++) {
			add_edge(source, i, 1, 0);
			add_edge(i, sink, 1, tbl[i].x*tbl[i].y*tbl[i].z);
			add_edge(i+N, sink, 1, 0);
		}
		printf("%d\n", minCostFlow(source, sink, N));
	}
	return 0;
}
