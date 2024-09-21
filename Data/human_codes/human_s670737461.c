// AOJ 2661 Todaiji
// 2018.3.19 bal4u

#include <stdio.h>
#include <string.h>
#include <math.h>

// [library]

//#define getchar_unlocked()  getchar()
int in()	// get non-negative integer from stdin
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

typedef struct { double x, y; } PP;
typedef struct { PP s, e; } SEG, LINE;

#define INF			1e8
#define EPS			1e-8

PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
double vabs(PP a) { return hypot(a.x, a.y); }
double cross(PP a, PP b) { return a.x * b.y - a.y * b.x; }
double dot(PP a, PP b) { return a.x * b.x + a.y * b.y; }
double norm(PP a) { return a.x * a.x + a.y * a.y; }
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

// [\library]  

PP seg1[55], seg2[55];

int main()
{
	int N1, N2, i, j;
	double ans, t;

	N1 = in(); seg1[0].x = 0, seg1[0].y = 0;
	for (i = 1; i <= N1; i++) seg1[i].x = in(), seg1[i].y = in();
	seg1[++N1].x = 1000, seg1[N1].y = 0;
	
	N2 = in(); seg2[0].x = 0, seg2[0].y = 1000;
	for (i = 1; i <= N2; i++) seg2[i].x = in(), seg2[i].y = in();
	seg2[++N2].x = 1000, seg2[N2].y = 1000;
	
	ans = INF;
	for (i = 0; i < N1; i++) for (j = 0; j < N2; j++) {
		t = distanceSS(seg1[i], seg1[i+1], seg2[j], seg2[j+1]);
		if (t < ans) ans = t;
	}
	printf("%.10lf\n", ans);
	return 0;
}
