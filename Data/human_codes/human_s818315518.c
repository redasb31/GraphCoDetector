// AOJ 1283 Most Distant Point from the Sea
// 2018.3.3 bal4u
 
#include <stdio.h>
#include <string.h>
#include <math.h>

#define LIM 40
#define EPS 1e-8

typedef struct { double x, y; } PP;
typedef struct { PP s, e; } SEG;

PP p[101], po[2][500];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int dcmp(double x) { if (fabs(x) < EPS) return 0; return x <= 0 ? -1 : 1; }
PP vadd(PP p1, PP p2) { PP r; r.x = p1.x + p2.x, r.y = p1.y + p2.y; return r; }
PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
PP vsmul(PP p, double k) { PP r; r.x = p.x * k, r.y = p.y * k; return r; }
PP vsdiv(PP p, double k) { PP r; r.x = p.x / k, r.y = p.y / k; return r; }
PP vmul(PP p1, PP p2) { PP r;
	r.x = p1.x * p2.x - p1.y * p2.y, r.y = p1.x * p2.y + p1.y * p2.x; return r; }
double cross(PP a, PP b) { return a.x * b.y - a.y * b.x; }
double dot(PP a, PP b) { return a.x * b.x + a.y * b.y; }
double norm(PP a) { return a.x * a.x + a.y * a.y; }
double vabs(PP a) { return hypot(a.x, a.y); }
int ccw(PP p0, PP p1, PP p2) { PP a, b;	double t;
	a = vsub(p1, p0), b = vsub(p2, p0), t = cross(a, b);
	if (t >  EPS) return 1;	if (t < -EPS) return -1;
	if (dot(a, b) < -EPS) return 2;	if (norm(a) < norm(b)) return -2;
	return 0;
}

// 線分と点の距離
double getDistanceSP(SEG s, PP p) {
	if (dot(vsub(s.e, s.s), vsub(p, s.s)) < -EPS) return vabs(vsub(p, s.s));
	if (dot(vsub(s.s, s.e), vsub(p, s.e)) < -EPS) return vabs(vsub(p, s.e));
	return fabs(cross(vsub(s.e, s.s), vsub(p, s.s))) / vabs(vsub(s.e, s.s));
}

// ２線分間の交点
PP crossPointS2P(SEG a, PP bs, PP be) { double a1, a2; PP r;
	a1 = cross(vsub(be, bs), vsub(a.s, bs));
	a2 = cross(vsub(be, bs), vsub(a.e, bs));
	r.x = (a.s.x*a2 - a.e.x*a1) / (a2-a1);
	r.y = (a.s.y*a2 - a.e.y*a1) / (a2-a1);
	return r;
}
PP crossPointSS(SEG a, SEG b) {	return crossPointS2P(a, b.s, b.e); }

// 凸包を直線で切断して左側をpo[]に残す
int convex_cut(SEG u, int n, PP *p, PP *po)		// p --> po
{
	int i, d1, d2, top = 0;
    for (i = 0; i < n; i++) {
        d1 = dcmp(cross(vsub(u.e, u.s), vsub(p[i],   u.s)));
        d2 = dcmp(cross(vsub(u.e, u.s), vsub(p[i+1], u.s)));
        if (d1 >= 0) po[top++] = p[i];
        if (d1*d2 < 0) po[top++] = crossPointS2P(u, p[i], p[i+1]);
    }
	po[top] = po[0];
    return top;
}

//直線の単位法線ベクトル
void unitnormalv(SEG *ans, SEG a) {
	PP t; double k = vabs(vsub(a.e, a.s));
	t.x = 0, t.y =  1; ans->s = vsdiv(vmul(vsub(a.e, a.s), t), k);
	t.x = 0, t.y = -1; ans->e = vsdiv(vmul(vsub(a.e, a.s), t), k);
}

//線分を距離dだけ平行移動
void parallelShift(SEG *ans, SEG a, double d) {
	SEG r; unitnormalv(&r, a);
	ans[0].s = vadd(a.s, vsmul(r.s, d));
	ans[0].e = vadd(a.e, vsmul(r.s, d));
	ans[1].s = vadd(a.s, vsmul(r.e, d));
	ans[1].e = vadd(a.e, vsmul(r.e, d));
}

int main()
{
	int n, i, j, k, k1, k2;
	double lo, hi, mi;
	SEG a, sft[2];

	while(n = in()) {
		for (i = 0; i < n; i++) p[i].x = in(), p[i].y = in();
		p[n] = p[0];

		lo = 0, hi = 10000;
		for (i = 0; i < LIM; i++) {
			mi = 0.5*(lo + hi);
			memcpy(po[0], p, sizeof(PP)*(n+1));
			k = n, k1 = 0, k2 = 1;
			for (j = 0; j < n; j++) {
				a.s = p[j], a.e = p[j+1];
				parallelShift(sft, a, mi);
				if (ccw(p[j], p[j+1], sft[0].s) == 1)
					 k = convex_cut(sft[0], k, po[k1], po[k2]);
				else k = convex_cut(sft[1], k, po[k1], po[k2]);
				if (!k) break;
				k1 = k2, k2 = !k2;
			}
			if (!k) hi = mi; else lo = mi;
		}
		printf("%.6lf\n", hi);
	}
	return 0;
}
