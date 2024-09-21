// AOJ CGL_7_H Intersection of a Circle and a Polygon
// 2019.3.23 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//// 平面幾何関連
typedef struct { double x, y; } PP;
typedef struct { PP s, e; } SEG, LINE;
typedef struct { double x, y, r; } C;

#define INF 1e8
#define EPS 1e-8
#define EQ(a,b)		(fabs((a)-(b))<EPS)
#define PPeQ(a,b)	(EQ(a.x,b.x)&&EQ(a.y,b.y))

int dcmp(double x) { if (fabs(x) < EPS) return 0; return x <= 0 ? -1 : 1; }
PP vset(double x, double y) { PP r; r.x = x, r.y = y; return r; }
PP vadd(PP p1, PP p2) { PP r; r.x = p1.x + p2.x, r.y = p1.y + p2.y; return r; }
PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
PP vsmul(PP p, double k) { PP r; r.x = p.x * k, r.y = p.y * k; return r; }
double vabs(PP a) { return hypot(a.x, a.y); }
double dist(PP p1, PP p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }
double cross(PP a, PP b) { return a.x * b.y - a.y * b.x; }
double dot(PP a, PP b) { return a.x * b.x + a.y * b.y; }
double norm(PP a) { return a.x * a.x + a.y * a.y; }
int ccw(PP p0, PP p1, PP p2) {
	PP a, b;	double t;
	a = vsub(p1, p0), b = vsub(p2, p0), t = cross(a, b);
	if (t > EPS) return 1;	if (t < -EPS) return -1;
	if (dot(a, b) < -EPS) return 2;	if (norm(a) < norm(b)) return -2;
	return 0;
}

// ２線分間の角度（符号付き）
double angle(PP now, PP next)
{
	double t1 = vabs(now)*vabs(next), t2 = dot(now, next);
	PP p = { 0,0 };
	if (EQ(t1, 0) || EQ(t1, t2)) return 0;
	t2 = fabs(acos(t2 / t1));
	if (ccw(p, now, next) < 0) t2 = -t2;
	return t2;
}

double distancePL(PP p, LINE ln)
{
	PP a = vsub(ln.e, ln.s);
	return fabs(cross(vsub(p, ln.s), a)) / vabs(a);
}

PP projection(PP p1, PP p2, PP p)
{
	PP p2p1 = vsub(p2, p1);
	PP pp1 = vsub(p, p1);
	return vadd(p1, vsmul(p2p1, dot(pp1, p2p1) / norm(p2p1)));
}

void crossPointCL(PP *p, C c, LINE line)
{
	PP c0 = vset(c.x, c.y);
	PP p0;
	double a, b;

	a = distancePL(c0, line), b = sqrt(c.r*c.r - a * a);
	p0 = projection(line.s, line.e, c0);
	p[0] = vadd(p0, vsmul(vsub(line.s, line.e), b / dist(line.s, line.e)));
	p[1] = vadd(p0, vsmul(vsub(line.e, line.s), b / dist(line.s, line.e)));
}

int ppOnSeg(PP p, SEG s)    // 点が線分の端点か内部にあるかどうか
{
	double x1 = s.s.x, y1 = s.s.y, x2 = s.e.x, y2 = s.e.y;
	double d;
	if (x1 >= x2) { d = x1, x1 = x2, x2 = d; d = y1, y1 = y2, y2 = d; }
	return x1 <= p.x && p.x <= x2 &&
		((y1 <= y2 && y1 <= p.y && p.y <= y2) ||
		(y1 > y2 && y2 <= p.y && p.y <= y1))
		&& EQ((p.y - y1)*(x2 - x1), (y2 - y1)*(p.x - x1));
}

PP po[105]; int N;
int R;
C oC;

// 三角形の面積計算（原点から）
double tri_area(PP now, PP next) {
	return 0.5 * cross(now, next);
}

// 扇形の面積計算
double sector_area(PP now, PP next, double r) {
	return 0.5 * r*r * angle(now, next);
}

// 両交点から選択
void choice(PP *cp, PP now, PP nxt, int k)
{
	SEG s;
	s.s = now, s.e = nxt;
	if (!ppOnSeg(cp[0], s)) cp[0] = cp[1];
	else if (PPeQ(cp[0], now) || PPeQ(cp[0], nxt)) cp[0] = cp[1];
	if (k == 1 || PPeQ(cp[1], now) || PPeQ(cp[1], nxt)) return;
	s.s = now, s.e = nxt;
	if (ppOnSeg(cp[0], s) && ppOnSeg(cp[1], s)) {
		if (dist(cp[1], now) < dist(cp[0], now)) {
			PP t; t = cp[1], cp[1] = cp[0], cp[0] = t;
		}
	}
}

// 円心（原点）と両頂点との面積をそれぞれ計算する
double calc(PP now, PP nxt)
{
	int d1, d2;
	PP cp[2];
	LINE s;
	double ans;

	s.s = now, s.e = nxt;
	d1 = dcmp(vabs(now) - R), d2 = dcmp(vabs(nxt) - R);
	if (d1 <= 0 && d2 <= 0) {     // 両点がともに円内
		ans = tri_area(now, nxt);
	}
	else if (d1 > 0 && d2 <= 0) { // 両点の片側が円外
		crossPointCL(cp, oC, s);
		choice(cp, now, nxt, 1);
		ans = sector_area(now, cp[0], R) + tri_area(cp[0], nxt);
	}
	else if (d1 <= 0 && d2 > 0) { // 両点の片側が円外
		crossPointCL(cp, oC, s);
		choice(cp, now, nxt, 1);
		ans = tri_area(now, cp[0]) + sector_area(cp[0], nxt, R);
	}
	else {
		if (distancePL(vset(0, 0), s) > R) goto Ex;
		crossPointCL(cp, oC, s);
		d1 = ppOnSeg(cp[0], s), d2 = ppOnSeg(cp[1], s);
		if (d1 && d2 && !PPeQ(cp[0], cp[1])) {   // 両点が円外だが、線分が一部円内
			choice(cp, now, nxt, 2);
			ans = tri_area(cp[0], cp[1]) +
				sector_area(now, cp[0], R) + sector_area(cp[1], nxt, R);
		}
		else {
Ex:			ans = sector_area(now, nxt, R);   // 両点がともに円外
		}
	}
	return ans;
}

int main()
{
	int i;
	double ans;

	scanf("%d%d", &N, &R);
	oC.r = R;                           // 原点に位置する円
	for (i = 0; i < N; i++) {
		int x, y; scanf("%d%d", &x, &y);
		po[i].x = x, po[i].y = y;
	}
	po[N] = po[0];

	ans = 0; for (i = 0; i < N; i++) ans += calc(po[i], po[i + 1]);
	printf("%.12lf\n", ans);
	return 0;
}
