// AOJ 2351 Closest Segment Pair
// 2018.3.17 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF     1e7
#define EPS     1e-5
#define RANGE	30
#define SIN     0.70710678118654752440084436210485    // Sin(45)
#define COS     0.70710678118654752440084436210485    // Cos(45)
#define SINCOS  SIN

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

typedef struct { double x1, y1, x2, y2; } S;
S seg[5105];

typedef struct { double x, y; } PP;
PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
double dot(PP a, PP b) { return a.x * b.x + a.y * b.y; }
double cross(PP a, PP b) { return a.x * b.y - a.y * b.x; }
double norm(PP a) { return a.x * a.x + a.y * a.y; }
double vabs(PP a) { return hypot(a.x, a.y); }
int ccw(PP p0, PP p1, PP p2) { PP a, b;	double t;
	a = vsub(p1, p0), b = vsub(p2, p0), t = cross(a, b);
	if (t >  EPS) return 1;	if (t < -EPS) return -1;
	if (dot(a, b) < -EPS) return 2;	if (norm(a) < norm(b)) return -2;
	return 0;
}
int is_intersectSS(PP s1s, PP s1e, PP s2s, PP s2e)
{
	return ccw(s1s, s1e, s2s) * ccw(s1s, s1e, s2e) <= 0 &&
		   ccw(s2s, s2e, s1s) * ccw(s2s, s2e, s1e) <= 0;
}
double distanceLP(PP ss, PP se, PP p) {
	return fabs(cross(vsub(se, ss), vsub(p, ss)) / vabs(vsub(se, ss))); }
double distanceSP(PP ss, PP se, PP p)
{
	if (dot(vsub(se, ss), vsub(p, ss)) < 0) return vabs(vsub(p, ss));
	if (dot(vsub(ss, se), vsub(p, se)) < 0) return vabs(vsub(p, se));
	return distanceLP(ss, se, p);
}
double distanceSS(PP s1s, PP s1e, PP s2s, PP s2e)
{
	double res, x;
	if (is_intersectSS(s1s, s1e, s2s, s2e)) return 0;
	res = distanceSP(s1s, s1e, s2s);
	x = distanceSP(s1s, s1e, s2e); if (x < res) res = x;
	x = distanceSP(s2s, s2e, s1s); if (x < res) res = x;
	x = distanceSP(s2s, s2e, s1e); if (x < res) res = x;
	return res;
}

int cmp(S *a, S *b)
{
	if (fabs(a->x1 - b->x1) < EPS) {
		if (fabs(a->y1 - b->y1) < EPS) return 0;
		if (a->y1 < b->y1) return -1; return 1;
	}
	if (a->x1 < b->x1) return -1; return 1;
}

int main()
{
	int N, i, j, lim;
	int x1, y1, x2, y2;
	double x, ans;
	PP s1s, s1e, s2s, s2e;

	N = in();
	if (N > 5100) { puts("0"); return 0; }
	for (i = 0; i < N; i++) {
		x1 = in(), y1 = in(), x2 = in(), y2 = in();
		seg[i].x1 = (x1 - y1) * SINCOS, seg[i].y1 = (x1 + y1) * SINCOS;
		seg[i].x2 = (x2 - y2) * SINCOS, seg[i].y2 = (x2 + y2) * SINCOS;
	}
	qsort(seg, N, sizeof(S), cmp);

	ans = INF;
	for (i = 0; i < N; i++) {
		s1s.x = seg[i].x1, s1s.y = seg[i].y1, s1e.x = seg[i].x2, s1e.y = seg[i].y2;
		lim = i+RANGE; if (lim > N) lim = N; 
		for (j = i+1; j < lim; j++) {
			s2s.x = seg[j].x1, s2s.y = seg[j].y1, s2e.x = seg[j].x2, s2e.y = seg[j].y2;
			x = distanceSS(s1s, s1e, s2s, s2e);
			if (x == 0) { ans = 0; goto done; }
			if (x < ans) ans = x;
		}
	}
done:
	printf("%.8lf\n", ans);
	return 0;
}
