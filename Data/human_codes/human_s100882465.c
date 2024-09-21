// AOJ 2151: Brave Princess Revisited
// 2017.11.11 bal4u@uu

#include <stdio.h>
#include <string.h>
#define TM 0
#if TM
#include <time.h>
#endif

typedef struct { int t, n, m; } QUE;
QUE que[20001]; int qsize;

#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)

void min_heapify(int i)
{
	int l, r, min;

	l = LEFT(i), r = RIGHT(i);
	if (l < qsize && que[l].t < que[i].t) min = l; else min = i;
	if (r < qsize && que[r].t < que[min].t) min = r;
	if (min != i) {
		QUE t = que[i]; que[i] = que[min]; que[min] = t;
		min_heapify(min);
	}
}

void deq()
{
//	if (qsize == 0) return 0;
//	*n = que[0].n, *m = que[0].m;
	que[0] = que[--qsize];
	min_heapify(0);
//	return 1;
}

void enq(int t, int n, int m)
{
	int i, min;

	i = qsize++;
	que[i].t = t, que[i].n = n, que[i].m = m;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		QUE tt = que[i]; que[i] = que[min]; que[min] = tt;
		i = min;
	}
}

typedef struct { int to[101], d[101], e[101]; } TBL;
TBL tbl[101];
int len[101];
int node[101][101]; int size;

int search(int start, int goal, int l)
{
	int s, m, i, k, e, p, ans;
	TBL *tp;

	qsize = 0;
	memset(node, 0x33, sizeof(node));
	node[start][l] = 0; enq(0, start, l);
	ans = 0x7fffff;
	while (qsize) {
		s = que[0].n, m = que[0].m, deq();
		p = node[s][m];
		if (s == goal) {
			if (p < ans) ans = p;
			if (ans == 0) break;
			continue;
		}

		for (tp = tbl + s, i = 0; i < len[s]; i++) {
			e = tp->to[i];

			k = p + tp->e[i];
			if (k < node[e][m]) node[e][m] = k, enq(node[e][m], e, m);

			k = m - tp->d[i];
			if (tp->d[i] <= m && p < node[e][k]) node[e][k] = p, enq(node[e][k], e, k);
		}
	}
	return ans;
}

char buf[30], *p;
int getint()
{
	int n = 0;
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}

int main()
{
	int n, m, l, a, b, d, e, i;
	TBL *tp;
#if TM
	clock_t start, end;
	start = clock();
#endif

	while (fgets(p=buf, 30, stdin) && *p != '0') {
		n = getint(), p++, m = getint(), p++, l = getint();
		memset(len, 0, sizeof(len));
		while (m--) {
			fgets(p=buf, 30, stdin);
			a = getint()-1, p++, b = getint()-1, p++, d = getint(), p++, e = getint();
			i = len[a], tp = tbl+a;
			tp->to[i] = b, tp->d[i] = d, tp->e[i] = e, len[a]++;
			i = len[b], tp = tbl+b;
			tp->to[i] = a, tp->d[i] = d, tp->e[i] = e, len[b]++;
		}
		size = n;
		printf("%d\n", search(0, n-1, l));
	}
#if TM
	end = clock();
	printf("time %lf\n", (double)(end-start)/CLOCKS_PER_SEC);
#endif
	return 0;
}