// AOJ 0275 Railroad
// 2018.2.21 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QMAX 10000
typedef struct { int t, s; } QUE;
QUE que[QMAX+2]; int qsize;

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
#define MAX 100003

int S;
int   hi[MAX], *to[MAX]; short *w[MAX];
int dist[MAX];
char  mk[MAX];
int  hi2[MAX], *to2[MAX];

int   q[MAX], top, tail;
typedef struct { int s, e; } T;
T ord[200002], _ord[200002]; int sz;
int f[200002];

int c[65], d[65];
unsigned long long dp[MAX];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

void dijkstra(int start)
{
	int i, s, e, d;

	memset(dist, INF, S << 2);
	qsize = 0;
	enq(start, 0), dist[start] = 0;
	while (qsize) {
		s = que[0].s, deq();
		for (i = 0; i < hi[s]; i++) {
			e = to[s][i], d = dist[s] + w[s][i];
			if (dist[e] < d) continue;
			if (dist[e] > d) hi2[e] = 0, dist[e] = d, enq(e, d);
			to2[e][hi2[e]++] = s;
		}
	}
}

void order(int goal)
{
    int i, k, s, e, max;

	q[0] = goal, top = 0, tail = 1;
	mk[goal] = 1;
	sz = 0, max = 0;
	while (top < tail) {
		s = q[top++];
		for (i = 0; i < hi2[s]; i++) {
			e = to2[s][i];
			if (!mk[e]) mk[e] = 1, q[tail++] = e;

			_ord[sz].s = e, _ord[sz++].e = s;
			k = dist[s];
			if (k > max) max = k;
			f[k]++;
		}
	}

	for (i = 1; i <= max; i++) f[i] += f[i-1];
	for (i = sz-1; i >= 0; i--) {
		k = dist[_ord[i].e], ord[--f[k]] = _ord[i];
	}
}

int main()
{
	int R, Q, u, v, _w, i, j, k;
	int *memo;
	unsigned long long mask;
	
	S = in()+1, R = in();
	memo = malloc(R*12);
	j = 0, i = R; while (i--) {
		memo[j++] = u = in(), hi[u]++;
		memo[j++] = v = in(), hi[v]++;
		memo[j++] = in();
	}
	for (i = 0; i < S; i++) if (hi[i]) {
		to [i] = malloc(hi[i] << 2), w[i] = malloc(hi[i] << 1);
		to2[i] = malloc(hi[i] << 2);
	}

	memset(hi, 0, S << 2);
	j = 0; while (R--) {
		u = memo[j++], v = memo[j++], _w = memo[j++];
		k = hi[u]++, to[u][k] = v, w[u][k] = _w;
		k = hi[v]++, to[v][k] = u, w[v][k] = _w;
	}
	free(memo);

	u = in(), v = in();
	dijkstra(u);
	order(v);

	Q = in(); for (i = 0; i < Q; ) {
		for (k = 0; k < 64 && i < Q; i++) c[k] = in(), d[k++] = in();
        memset(dp, 0, S << 3);
		mask = 1; for (j = 0; j < k; j++) dp[c[j]] |= mask, mask <<= 1;
		for (j = 0; j < sz; j++) dp[ord[j].e] |= dp[ord[j].s];
        mask = 1; for (j = 0; j < k; j++) {
            puts(dp[d[j]] & mask? "Yes": "No"), mask <<= 1;
		}
    }
	return 0;
}

