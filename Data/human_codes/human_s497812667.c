// AOJ 1088 School Excursion
// 2018.3.7 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QMAX 10005
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
#define MAX 4004
typedef struct { int to, rev; int cap, cost; } E;
E *edge[MAX]; int hi[MAX], lim[MAX];
int V;				// 頂点数
int potential[MAX], min_cost[MAX], prevv[MAX], preve[MAX];

void check_lim(int a)
{
	if (hi[a] < lim[a]) return;
	if (lim[a] == 0) {
		lim[a] = 4, hi[a] = 0;
		edge[a] = malloc(sizeof(E) *lim[a]);
	} else if (hi[a] == lim[a]) {
		int k = lim[a];
		if (k > 512) k = 512;
		lim[a] += k;
		edge[a] = realloc(edge[a], sizeof(E) *lim[a]);
	}
}

void add_edge(int from, int to, int cap, int cost)
{
	int f, t;
	E *ep;

	check_lim(from), check_lim(to);
	f = hi[from]++, t = hi[to]++;
	ep = &edge[from][f], ep->to = to, ep->cap = cap, ep->cost = cost, ep->rev = t; 
	ep = &edge[to][t], ep->to = from, ep->cap = 0, ep->cost = -cost, ep->rev = f;
}

int minCostFlow(int *f, int S, int T, int F)
{
	int i, s, ns, t, nt, ret;
	E *ep;

	ret = 0;
	memset(potential, 0, V << 2);
  
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
		if (min_cost[T] == INF) { *f = F; return ret; }
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
	*f = 0;
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

int  tm[4004];		// time

int main()
{
	int n, i, j, k, m, x, y, g;
	int pf, pe, cf, ce, nf, ne, source, sink;	// prev, cur, next

	while (n = in()) {
		memset(hi, 0, sizeof(hi)), memset(lim, 0, sizeof (lim));	// for MCF

		pf = pe = source = 0, tm[pf] = -1;
		for (i = 1; i < n; i++) {
			m = in();
			cf = pe+1, ce = cf+m-1, nf = ce+1, ne = nf-1;
			for (j = 0; j < m; j++) {
				tm[cf+j] = x = in(),
				y = in();
				for (k = nf; ; k++) {
					if (k > ne) { k = ++ne, tm[k] = y; break; } 
					if (y == tm[k]) break;
				}
				add_edge(cf+j, k, 1, in());
			}
			for (j = pf; j <= pe; j++) for (k = cf; k <= ce; k++) {
				if (tm[j] <= tm[k]) add_edge(j, k, 1, 0);
			}
			pf = nf, pe = ne;
		}
		sink = pe+1, V = sink+1;
		for (j = pf; j <= pe; j++) add_edge(j, sink, 1, 0);

		g = in();
		y = minCostFlow(&x, source, sink, g);
		printf("%d %d\n", g-x, y);

		for (i = 0; i < V; i++) if (lim[i]) free(edge[i]);
	}
	return 0;
}
