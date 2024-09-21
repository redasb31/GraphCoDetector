// AOJ 2293 Dangerous Tower
// 2018.3.6 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QMAX 3005
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
#define MAX 3005
typedef struct { short to, rev; int cap, cost; } E;
E edge[MAX][MAX]; short hi[MAX];
int V;				// 頂点数
int potential[MAX], min_cost[MAX]; short prevv[MAX], preve[MAX];

void add_edge(int from, int to, int cap, int cost)
{
	int f = hi[from]++, t = hi[to]++;
	E *ep = &edge[from][f]; ep->to = to, ep->cap = cap, ep->cost = cost, ep->rev = t; 
	ep = &edge[to][t], ep->to = from, ep->cap = 0, ep->cost = -cost, ep->rev = f;
}

int minCost(int S, int T, int F)
{
	int i, s, ns, t, nt, ret;
	E *ep;

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
				nt = min_cost[s] + ep->cost + potential[s] - potential[ns];
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
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int a[1002], b[1002];
int block[2002]; int sz;

int cmp(int *a, int *b) { return *a - *b; }

int uniq(int *a, int n)
{
	int i, j;
	
	for (i = 0, j = 1; j < n; j++) {
		while (j < n && a[j] == a[i]) j++;
		if (j < n) if (++i != j) a[i] = a[j];
	}
	return i+1;
}

int bsch(int x)
{
	int m, l = 0, r = sz;

    while (l < r) {
        m = (l + r) >> 1;
        if (block[m] < x) l = m + 1; else r = m;
    }
	return l;
}

int main()
{
	int N, i, j;

	N = in();
	sz = 0; for (i = 0; i < N; i++) block[sz++] = a[i] = in(), block[sz++] = b[i] = in();
	qsort(block, sz, sizeof(int), cmp);
//	sz = uniq(block, sz);

	V = (N + sz) + 2;
	for (j = 0; j < N; j++) {
		i = bsch(a[j]), add_edge(i+2, sz+2+j, 1, -b[j]);
		i = bsch(b[j]), add_edge(i+2, sz+2+j, 1, -a[j]);
	}
	for (i = 0; i < sz; i++) add_edge(0,      i+2, 1, 0);
	for (j = 0; j < N;  j++) add_edge(sz+2+j, 1,   1, 0);
	add_edge(0, 1, 3003, 0);
	printf("%d\n", -minCost(0, 1, N << 1));
	return 0;
}
