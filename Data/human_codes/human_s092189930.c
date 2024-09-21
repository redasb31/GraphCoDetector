// AOJ 2673 Do You Divide It?
// 2018.5.6 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { int x, y; } PP;

#define INF		 10000000
#define EPS		 1e-8
#define EQ(a,b)	 (fabs((a)-(b))<EPS)

int fcmp(double x) { if (fabs(x) < EPS) return 0; return x <= 0 ? -1 : 1; }

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

PP p[102];
double yy1[102], yy2[102];

int cmp(double *a, double *b) {	return fcmp(*a - *b); }

double calc(int i, int x)
{
	double a = ((double)(p[i+1].y - p[i].y))/(p[i+1].x - p[i].x);
	return a*(x - p[i].x) + p[i].y;
}

int main()
{
	int N, i, j, k, x, xmin, xmax;
	double s, odd, even;

	N = in();
	xmin = INF, xmax = -INF;
	for (i = 0; i < N; i++) {
		p[i].x = x = in()<<1, p[i].y = in();
		if (x < xmin) xmin = x;
		if (x > xmax) xmax = x;
	}
	p[N] = p[0];

	odd = 0, even = 0;
	for (k = 0, x = xmin; x < xmax; x++, k++) {
		j = 0;
		for (i = 0; i < N; i++) {
			if ((p[i].x <= x   && p[i+1].x <= x) ||
				(p[i].x >= x+1 && p[i+1].x >= x+1)) continue;
			yy1[j] = calc(i, x);
			yy2[j] = calc(i, x+1);
			j++;
		}
		qsort(yy1, j, sizeof(double), cmp);
		qsort(yy2, j, sizeof(double), cmp);

		s = 0;
		for (i = 0; i < j; i+=2) s +=  yy1[i+1] - yy1[i];
		for (i = 0; i < j; i+=2) s +=  yy2[i+1] - yy2[i];
		if (k & 1) odd += s;
		else      even += s;
	}
	if (odd < even) odd = even;
	printf("%.10lf\n", odd/4);
	return 0;
}

