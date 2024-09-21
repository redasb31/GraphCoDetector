// AOJ 2497 One
// 2018.3.18 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIV       1000
#define EPS       1e-10
#define EQ(a,b)   (fabs((a)-(b))<EPS)

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	if (c == '-') {	c = getchar_unlocked();
		do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
		return -n;
	}
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

int quadeq(double *x1, double *x2, double a, double b, double c) // ax^2 + bx + c = 0
{
	double d;

	if (EQ(a, 0)) {	if (!EQ(b, 0)) { *x1 = -c/b; return 1; } return 0; }
	b /= a, c /= a;	if (EQ(c, 0)) { *x1 = -b; return 1; }
	b /= 2.0, d = b*b-c;
	if (EQ(d, 0)) { *x1 = -b; return 1; }
	if (d <= 0) return 0;
	d = sqrt(d), *x1 = -b-d, *x2 = -b+d;
	return 2;
}

double fa, fp; double f(double x)
{
	double v = 2 * fa * (x - fp);
	return sqrt(1+v*v);
}
double integral(double xmin, double xmax)
{
	int i;
	double h, h2, x, ans;
	h = (xmax-xmin)/DIV, h2 = 0.5*h, x = xmin;
	ans = 0, i = DIV; while (i--) ans += f(x) + 4*f(x+h2) + f(x+h), x += h;
	return ans*h/6;
}


typedef struct { int a, p, q; } T;
T t[52];
double xx[10000]; int sz;

int cmp(double *a, double *b) { if (EQ(*a, *b)) return 0; if (*a <= *b) return -1; return 1; }

int main()
{
	int  W, H, N, i, j, k, f;
	double a, b, c, x1, x2, x;
	double ans, y, max, r;

	W = in(), H = in(), N = in();
	for (i = 0; i < N; i++) t[i].a = in(), t[i].p = in(), t[i].q = in();

	ans = 0, xx[0] = 0, sz = 1;
	for (i = 0; i < N; i++) for (j = i+1; j < N; j++) {
		a = t[i].a - t[j].a;
		b = -2*(t[i].a*t[i].p - t[j].a*t[j].p);
		c = t[i].a*t[i].p*t[i].p - t[j].a*t[j].p*t[j].p + t[i].q-t[j].q;
		k = quadeq(&x1, &x2, a, b, c);
		if (k  > 0) xx[sz++] = x1;
		if (k == 2) xx[sz++] = x2;
	}
	xx[sz++] = W;
	qsort(xx, sz, sizeof(double), cmp);

	for (i = 1; i < sz; i++) {
		x1 = xx[i-1], x2 = xx[i];
		x = (x1+x2)/2, max = 0, f = -1;
		for (k = 0; k < N; k++) {
			y = t[k].a*(x-t[k].p)*(x-t[k].p) + t[k].q;
			if (y > max) f = k, max = y;
		}
		if (f < 0) continue;

		r = sqrt((double)t[f].q/(-t[f].a));
		if (x1 < t[f].p-r) x1 = t[f].p-r;
		if (x2 > t[f].p+r) x2 = t[f].p+r;
		fa = t[f].a, fp = t[f].p, ans += integral(x1, x2);
	}
	printf("%.15lf\n", ans);
	return 0;
}
