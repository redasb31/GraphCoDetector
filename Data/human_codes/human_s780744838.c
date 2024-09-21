// AOJ 2095 Nagashi Soumen
// 2018.3.11 bal4u

#include <stdio.h>
#include <string.h>
#include <math.h>

#define QMAX 2000
typedef struct { int s; double t; } QUE;
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

void enq(int s, double t)
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

#define INF 1e6
#define EPS 1e-12
#define MAX 210
typedef struct { int to, rev; int cap; double cost; } EDGE;
EDGE edge[MAX][MAX]; int hi[MAX];
int V;				// 頂点数
double potential[MAX], dist[MAX]; prevv[MAX], preve[MAX];

void add_edge(int from, int to, int cap, double cost)
{
	int f, t;
	EDGE *ep;

	f = hi[from]++, t = hi[to]++;
	ep = &edge[from][f], ep->to = to, ep->cap = cap, ep->cost = cost, ep->rev = t; 
	ep = &edge[to][t], ep->to = from, ep->cap = 0, ep->cost = -cost, ep->rev = f;
}

double minCostFlow(int S, int T, int F)
{
	int i, v, nv, d;
	double ret, t, nt;
	EDGE *ep;

	ret = 0;
	memset(potential, 0, sizeof(potential));
  
	while (F > 0) {
		for (i = 0; i < V; i++) dist[i] = INF;
		qsize = 0;
		enq(S, 0), dist[S] = 0;
		while (qsize) {
			v = que[0].s, t = que[0].t, deq();
			if (dist[v] < t) continue;
			for (i = 0; i < hi[v]; i++) {
				ep = &edge[v][i];
				if (ep->cap <= 0) continue;
				nv = ep->to;
				nt = t + ep->cost - potential[nv] + potential[v];
				if(dist[nv] > nt + EPS) {
					dist[nv] = nt;
					prevv[nv] = v, preve[nv] = i;
					enq(nv, nt);
				}
			}
		}
		if (dist[T] == INF) return -1;
		for (v = 0; v < V; v++) potential[v] += dist[v];

		d = F;
		for (v = T; v != S; v = prevv[v]) {
			ep = &edge[prevv[v]][preve[v]];
			if (d > ep->cap) d = ep->cap;
		}
		F -= d;

		ret += d * potential[T];
		for (v = T; v != S; v = prevv[v]) {
			ep = &edge[prevv[v]][preve[v]];
			ep->cap -= d;
			edge[v][ep->rev].cap += d;
		}
	}
	return ret;
}

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	if (c == '-') {
		c = getchar_unlocked();
		do n = 10*n + (c & 0xf), c = getchar_unlocked();
		while (c >= '0');
		return -n;
	}
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

#define VMAX 512
#define BASE 100
int x[102], y[102], z[102];
char cnt[202];

double dd(int i, int j) { int dx = x[i]-x[j], dy = y[i]-y[j], dz = z[i]-z[j];
	return sqrt(dx*dx + dy*dy + dz*dz);
}

int main()
{
	int N, K, i, j;
	int source, sink;

	while (N = in()) {
		K = in();
		for (i = 0; i < N; i++) x[i] = in(), y[i] = in(), z[i] = in();
		if (N <= K) { puts("0.000000000000000"); continue; }

		memset(cnt, 0, sizeof(cnt));
		for (i = 0; i < N; i++) {
			if (++cnt[BASE+z[i]] > K) break;
		}
		if (i < N) { puts("-1"); continue; }

		source = N << 1, sink = source + 1, V = sink + 1;
		memset(hi, 0, V << 2);

		for (i = 0; i < N; i++) {
			add_edge(source, i, 1, 0);
			add_edge(i, N+i, 1, -VMAX);
			for (j = 0; j < N; j++) if (z[j] > z[i]) add_edge(N+j, i, 1, dd(i, j));
			add_edge(N+i, sink, 1, 0);
		}
		printf("%.15lf\n", minCostFlow(source, sink, K) + N*VMAX);
	}
	return 0;
}
