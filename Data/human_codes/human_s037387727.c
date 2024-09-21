// AOJ DSL_4_A Union of Rectangles
// 2018.5.14 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()
{
	int n = 0, c = gc();
	if (c == '-') {	c = gc();
		do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
		return -n;
	}
	do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

#define MAX_N 2005
#define MAX   4005

typedef struct { int x1, y1, x2, y2; } TBL;
TBL tbl[MAX_N];

int x[MAX], xs;
int y[MAX], ys;
int xx[MAX], yy[MAX];

short s[2][MAX];
short hi[MAX];
short a[MAX][MAX][2];

int cmp(int *a, int *b) { return *a - *b; }

int bsch(int *a, int x, int r)
{
	int m, l = 0;

    while (l < r) {
        m = (l + r) >> 1;
		if (a[m] == x) return m;
        if (a[m] < x) l = m + 1; else r = m;
    }
	return l-1;
}

int uniq(int *a, int n)
{
	int i, j;
	
	for (i = 0, j = 1; j < n; j++) {
		while (j < n && a[j] == a[i]) j++;
		if (j < n) if (++i != j) a[i] = a[j];
	}
	return i+1;
}

int main()
{
	int N, i, j, x1, y1, x2, y2, k1, k2;
	long long ans;

	N = in(); xs = ys = 0;
	for (i = 0; i < N; i++) {
		tbl[i].x1 = x1 = in(), tbl[i].y1 = y1 = in();
		tbl[i].x2 = x2 = in(), tbl[i].y2 = y2 = in();
		x[xs++] = x1, x[xs++] = x2;
		y[ys++] = y1, y[ys++] = y2;
	}
	qsort(x, xs, sizeof(int), cmp); xs = uniq(x, xs);
	qsort(y, ys, sizeof(int), cmp); ys = uniq(y, ys);

	for (j = 0, i = 0; i < N; i++) {
		x1 = bsch(x, tbl[i].x1, xs);
		x2 = bsch(x, tbl[i].x2, xs);
		y1 = bsch(y, tbl[i].y1, ys);
		y2 = bsch(y, tbl[i].y2, ys);
		xx[x1] = tbl[i].x1, xx[x2] = tbl[i].x2;
		yy[y1] = tbl[i].y1, yy[y2] = tbl[i].y2;

		a[y1][hi[y1]][0] = x1, a[y1][hi[y1]++][1] = 1;
		a[y1][hi[y1]][0] = x2, a[y1][hi[y1]++][1] = -1;
		a[y2][hi[y2]][0] = x1, a[y2][hi[y2]++][1] = -1;
		a[y2][hi[y2]][0] = x2, a[y2][hi[y2]++][1] = 1;
	}

	ans = 0;
	for (k1 = 1, k2 = 0, j = 0; j < ys; j++, k1 = k2, k2 = !k2) {
		memset(s[k2], 0, sizeof(s[k2]));
		for (i = 0; i < hi[j]; i++) s[k2][a[j][i][0]] += a[j][i][1];
		for (i = 0; i < xs; i++) {
			s[k2][i+1] += s[k2][i];
			s[k2][i] += s[k1][i];
		}
		for (i = 0; i < xs; i++) if (s[k2][i]) {
			ans += (long long)(xx[i+1]-xx[i])*(long long)(yy[j+1]-yy[j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

