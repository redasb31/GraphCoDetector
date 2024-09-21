// AOJ 1311: Test Case Tweaking
// 2018.1.13 bal4u

#include <stdio.h>
#include <string.h>

#define QMAX 400000
typedef struct { int t, s, d; } QUE;
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

void enq(int s, int t, int d)
{
	int i, min;
	QUE qt;

	i = qsize++;
	que[i].s = s, que[i].t = t, que[i].d = d;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		i = min;
	}
}

int to[101][101], dt[101][101], hi[101];
int used[101][101];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int dijkstra(int n, int c, int start, int goal)
{
	int i, s, t, d, e, t2, ans;

	memset(used, -1, sizeof(used));
	qsize = 0;
	ans = 10000;
	enq(start, 0, 0);
	while (qsize) {
		s = que[0].s, t = que[0].d, d = que[0].t, deq();
		if (s == goal) {
			if (d < ans) ans = d;
			continue;
		}
		if (used[s][d] >= 0) continue;
		used[s][d] = t;
		for (i = 0; i < hi[s]; i++) {
			e = to[s][i];
			t2 = t+dt[s][i];
//			if (dt[s][i] > 0) {
				if (d < n) enq(e, d+1, t);
//			}
			if (t2 <= c) enq(e, d, t2);
		}
	}
	return ans;
}

int main()
{
	int n, m, c, f, k;
	
	while (n = in()) {
		m = in(), c = in();
		memset(hi, 0, sizeof(hi));

		while (m--) {
			f = in()-1, k = hi[f]++;
			to[f][k] = in()-1, dt[f][k] = in();
		}
		printf("%d\n", dijkstra(n, c, 0, n-1));
	}
	return 0;
}
