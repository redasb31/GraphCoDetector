// AOJ 1058 Winter Bells
// 2018.3.1 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QMAX 15000
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
int hi[101], to[101][101], w[101][101];
int dist1[101], dist2[101];
int shot1[101], shot2[101];  

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

void dijkstra(int n, int start, int *dist, int *shot)
{
	int i, s, d, e;

	memset(dist, INF, n << 2);
	memset(shot, 0, n << 2);
	qsize = 0;
	dist[start] = 0, shot[start] = 1, enq(start, 0);
	while (qsize) {
		s = que[0].s, deq();
		for (i = 0; i < hi[s]; i++) {
			e = to[s][i], d = dist[s] + w[s][i];
			if (dist[e] < d) continue;
			if (dist[e] > d) shot[e] = shot[s], dist[e] = d, enq(e, d);
			else shot[e] += shot[s];
		}
	}
}

int main()
{
	int n, m, p, k, a, b, c;

	while (n = in()) {
		m = in(), p = in();

		memset(hi, 0, n << 2);
		while (m--) {
			a = in(), b = in(), c = in();
			k = hi[a]++, to[a][k] = b, w[a][k] = c;
			k = hi[b]++, to[b][k] = a, w[b][k] = c;
		}

		dijkstra(n,   0, dist1, shot1);
		dijkstra(n, n-1, dist2, shot2);

		while (p--) {
			c = in();
			if (dist1[c] + dist2[c] == dist1[n-1])
				printf("%.8lf\n", ((double)shot1[c] * shot2[c]) / (double)shot1[n-1]);
			else puts("0.00000000");
		}
		putchar('\n');
	}
	return 0;
}
