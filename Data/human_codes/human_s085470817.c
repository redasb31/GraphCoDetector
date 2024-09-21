// AOJ 2913 Prime Routing
// 2019.4.5 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//// 高速入力
#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}


//// 優先度付きキュー（ダイクストラ法のため）
#define MAX 1000000
typedef struct { int t, node; } QUE;
QUE que[MAX]; int qsize;

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

void enq(int n, int t)
{
	int i, min;
	QUE qt;

	i = qsize++;
	que[i].node = n, que[i].t = t;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		i = min;
	}
}


//// ダイクストラ法で最短距離
int N;
int hi[100002], *to[100002];
char vis[100002][2];

int dijkstra(int start, int goal)
{
	int i, s, e, t, f;

//	memset(vis, 0, N * sizeof(int));
	qsize = 0, f = 0;
	enq(start, 0);
	while (qsize) {
		s = que[0].node, t = que[0].t, deq();
		if (s == goal) {
			if (t == 1) f = 1;
			else if (t == 2 || (t & 1)) return t;
		}
		if (vis[s][t & 1]) continue;
		vis[s][t & 1] = 1;

		t++;
		for (i = 0; i < hi[s]; i++) {
			e = to[s][i];
			if (!vis[e][t & 1]) enq(e, t);
		}
	}
	if (f) return 3;
	return -1;
}

int isPrime(int n)
{
	int i, b;
	if (n == 2) return 1;
	if (n <= 1 || (n & 1) == 0) return 0;
	b = (int)sqrt(n);
	for (i = 3; i <= b; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int i, k, M, S, T, a, b;
	int *memo, sz;

	N = in(), M = in(), S = in() - 1, T = in() - 1;

	memo = malloc(M * 2 * sizeof(int));
	sz = 0;	for (i = 0; i < M; i++) {
		memo[sz++] = a = in() - 1, memo[sz++] = b = in() - 1;
		hi[a]++, hi[b]++;
	}
	for (i = 0; i < N; i++) if (hi[i]) to[i] = malloc(hi[i] * sizeof(int));
	memset(hi, 0, N * sizeof(int));

	i = 0; while (i < sz) {
		a = memo[i++], b = memo[i++];
		k = hi[a]++, to[a][k] = b;
		k = hi[b]++, to[b][k] = a;
	}
//	free(memo);

	k = dijkstra(S, T);
	if (k > 0 && k & 1)	while (!isPrime(k)) k += 2;
	printf("%d\n", k);
	return 0;
}

