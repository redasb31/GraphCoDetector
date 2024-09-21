// AOJ 0253 Ant Nest
// 2018.3.14 bal4u

#include <stdio.h>
#include <math.h>

#define LIM 40
#define EPS 1e-8

typedef struct { double x, y; } PP;
typedef struct { PP s, e; } SEG, LINE;

PP p[102], po[500];

#define EQ(a,b)  (fabs((a)-(b))<EPS)
int dcmp(double x) { if (fabs(x) < EPS) return 0; return x <= 0 ? -1 : 1; }
PP vadd(PP p1, PP p2) { PP r; r.x = p1.x + p2.x, r.y = p1.y + p2.y; return r; }
PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
PP vsmul(PP p, double k) { PP r; r.x = p.x * k, r.y = p.y * k; return r; }
PP vmul(PP p1, PP p2) { PP r;
	r.x = p1.x * p2.x - p1.y * p2.y, r.y = p1.x * p2.y + p1.y * p2.x; return r; }
double cross(PP a, PP b) { return a.x * b.y - a.y * b.x; }
double dot(PP a, PP b) { return a.x * b.x + a.y * b.y; }
double vabs(PP a) { return hypot(a.x, a.y); }

// 点と直線の距離
double distancePL(PP p, LINE ln) { PP a = vsub(ln.e, ln.s);
	return fabs(cross(vsub(p, ln.s), a)) / vabs(a);
}

// ２線分間の交点
PP crossPointS2P(SEG a, PP bs, PP be) { double a1, a2; PP r;
	a1 = cross(vsub(be, bs), vsub(a.s, bs));
	a2 = cross(vsub(be, bs), vsub(a.e, bs));
	r.x = (a.s.x*a2 - a.e.x*a1) / (a2-a1);
	r.y = (a.s.y*a2 - a.e.y*a1) / (a2-a1);
	return r;
}

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
	t.x = 0, t.y =  1; ans->s = vsmul(vmul(vsub(a.e, a.s), t), 1/k);
	t.x = 0, t.y = -1; ans->e = vsmul(vmul(vsub(a.e, a.s), t), 1/k);
}

//線分を距離dだけ平行移動
void parallelShift(SEG *ans, SEG a, double d) {
	SEG r; unitnormalv(&r, a);
	ans[0].s = vadd(a.s, vsmul(r.s, d));
	ans[0].e = vadd(a.e, vsmul(r.s, d));
	ans[1].s = vadd(a.s, vsmul(r.e, d));
	ans[1].e = vadd(a.e, vsmul(r.e, d));
}

//ポリゴンの面積
double poly_area(int n, PP *p)
{
   int i; double s;
   for (s = 0, i = 0; i < n; i++) s += (p[i].x-p[i+1].x) * (p[i].y+p[i+1].y);
   return fabs(s)/2;
}


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

int main()
{
	int n, d, V, i, j;
	int ii, jj, lim, f;
	double S, s, ans, a, lo, hi, mi;
	LINE ln, cut[2];

	while (n = in()) {
		d = in(), V = in(), S = (double)V / d;
		for (i = 0; i < n; i++) p[i].x = in(), p[i].y = in(); p[n] = p[0];

		s = poly_area(n, p);

		ans = 0;
		for (i = 0; i < n; i++) for (j = 0; j < n; j++) if (i != j && i != j+1) {
			ln.s = p[j], ln.e = p[j+1];
			if ((a = distancePL(p[i], ln)) > ans) ans = a, ii = i, jj = j+1;
		}
		if (EQ(s, S) || s <= S) { printf("%lf\n", ans);	continue; }

		ln.s = p[jj], ln.e = p[jj-1];
		lo = 0, hi = ans;
		lim = LIM; while (lim--) {
			mi = (lo + hi)*0.5;
			parallelShift(cut, ln, mi);
			i = convex_cut(cut[1], n, p, po);
			f = 0;
			if (i >= 3 && poly_area(i, po) >= S) f = 1; 
			else {
				i = convex_cut(cut[0], n, p, po);
				if (i >= 3 && poly_area(i, po) >= S) f = 1;
			}
			if (f) hi = mi; else lo = mi;
		}
		printf("%lf\n", hi);
	}
	return 0;
}
