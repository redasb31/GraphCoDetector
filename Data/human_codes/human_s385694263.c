// AOJ 2457 Adhoc Translation
// 2018.3.6 bal4u

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
#define MAX 805
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
		if (k > 128) k = 128;
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

typedef struct { int c, w; char *s; } S;	// w:len, c:cnt
S web[50000]; int wsz;
S dic[402]; int dsz;
char buf[102][1005];
char word[402][25];

int string_distance(char *s1, int w1, char *s2, int w2)
{
	int  i, j, d, min;
	static int dp[30][30];

	for (j = 0; j <= w1; j++) dp[j][0] = j;
	for (i = 0; i <= w2; i++) dp[0][i] = i;
	for (j = 1; j <= w1; j++) for (i = 1; i <= w2; i++) {
        d = (s1[j-1] != s2[i-1]);
        min =     dp[j-1][i  ] + 1;
        if (min > dp[j  ][i-1] + 1) min = dp[j  ][i-1] + 1;
        if (min > dp[j-1][i-1] + d) min = dp[j-1][i-1] + d;
        dp[j][i] = min;
	}
	return dp[w1][w2];
}

int cmp(S *a, S *b) { return strcmp(a->s, b->s); }

int uniq(S *a, int n)
{
	int i, j, k;
	
	for (i = 0, j = 1; j < n; j++) {
		k = j; while (j < n && a[i].w == a[j].w && !memcmp(a[i].s, a[j].s, a[i].w)) j++;
		a[i].c = j-k+1; if (j < n) if (++i != j) a[i] = a[j];
	}
	a[i].c = j-k;
	return i+1;
}

int main()
{
	int N, M, i, j, k, source, sink;
	char b[20], *p, *q;

	fgets(b, 20, stdin), sscanf(b, "%d%d", &N, &M);
	wsz = 0; for (i = 0; i < N; i++) {
		fgets(p=buf[i], 1002, stdin);
		while (1) {
			while (*p == ' ') p++;
			q = p; while (*p > ' ') p++;
			web[wsz].c = 1, web[wsz].s = q, web[wsz++].w = p-q;
			if (*p < ' ') { *p = 0; break; }
			*p++ = 0;
		}
	}

	dsz = 0; for (i = 0; i < M; i++) {
		fgets(p=word[i], 22, stdin);
		while (*p == ' ') p++;
		q = p; while (*p > ' ') p++; *p = 0;
		dic[dsz].s = q, dic[dsz++].w = p-q;
	}

	qsort(web, wsz, sizeof(S), cmp);
	wsz = uniq(web, wsz);
	qsort(dic, dsz, sizeof(S), cmp);
	dsz = uniq(dic, dsz);

	source = 0, sink = wsz + dsz + 1, V = sink + 1;

	for (i = 0; i < wsz; i++) {
		add_edge(source, i+1, 1, 0);
		for (j = 0; j < dsz; j++) {
			k = web[i].c * string_distance(web[i].s, web[i].w, dic[j].s, dic[j].w);
			add_edge(i+1, wsz+j+1, 1, k);
			if (i == 0) add_edge(wsz+j+1, sink, 1, 0);
		}
	}

	printf("%d\n", minCost(source, sink, wsz));
	return 0;
}
