// AOJ 2155: Infected Computer
// 2017.10.20 bal4u@uu
// 2018.2.4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int t, s, d; } T;
T tbl[20002], *end;
char f[20002];

int cmp(T *a, T *b) { return a->t - b->t; }

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int main()
{
	int n, m, ans;
	T *t;
	char *q;

	while (n = in()) {
		m = in();
		memset(f, 0, n+1);
		end = tbl + m; for (t = tbl; t < end; t++) t->t = in(), t->s = in(), t->d = in();
		qsort(tbl, m, sizeof(T), cmp);
		f[1] = 1; for (t = tbl; t < end; t++) f[t->d] |= f[t->s];
		ans = 0, q = f+1; while (n--) ans += *q++;
		printf("%d\n", ans);
	}
	return 0;
}

