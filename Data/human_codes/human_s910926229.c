// AOJ 2201 Immortal Jewels
// 2018.3.11 bal4u
 
#include <stdio.h>
#include <math.h>

#define EPS			1e-8

typedef struct { double x, y; } PP;
typedef struct { PP s, e; } LINE;
typedef struct { PP p; double r; } C;

C    c[102]; int sc;
LINE line[40001]; int sl;

#define EQ(a,b)		(fabs((a)-(b))<EPS)
#define PPeQ(a,b)	(EQ(a.x,b.x)&&EQ(a.y,b.y))
int dcmp(double x) { if (fabs(x) < EPS) return 0; return x <= 0 ? -1 : 1; }
PP vset(double x, double y) { PP r; r.x = x, r.y = y; return r; }
void lset(LINE *ln, PP a, PP b) { ln->s = a, ln->e = b; }
PP vadd(PP p1, PP p2) { PP r; r.x = p1.x + p2.x, r.y = p1.y + p2.y; return r; }
PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
PP vsmul(PP p, double k) { PP r; r.x = p.x * k, r.y = p.y * k; return r; }
PP vmul(PP p1, PP p2) { PP r;
	r.x = p1.x * p2.x - p1.y * p2.y, r.y = p1.x * p2.y + p1.y * p2.x; return r; }
double cross(PP a, PP b) { return a.x * b.y - a.y * b.x; }
double vabs(PP a) { return hypot(a.x, a.y); }

double distancePL(PP p, LINE ln) {
	return fabs(cross(vsub(p, ln.s), vsub(ln.s, ln.e))) / vabs(vsub(ln.s, ln.e)); }

double distanceLC(LINE ln, C c) { return distancePL(c.p, ln); }

int is_containCC(C c1, C c2) { return dcmp(vabs(vsub(c1.p, c2.p)) + c2.r - c1.r) < 0; }

int is_interCC(C c1, C c2) {
	return !is_containCC(c1, c2) && !is_containCC(c2, c1) &&
		   dcmp(vabs(vsub(c1.p, c2.p)) - (c1.r + c2.r)) <= 0;
}

void intersectCC(PP *p1, PP *p2, C c1, C c2)
{
	double d = vabs(vsub(c1.p, c2.p));
	double cos = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
	double sin = sqrt(c1.r * c1.r - cos * cos);
	PP p = vsmul(vsub(c1.p, c2.p), 1 / d);
	*p1 = vadd(c1.p, vmul(p, vset(cos, sin))), *p2 = vadd(c1.p, vmul(p, vset(cos, -sin)));
}

void tangentLP(LINE *ln, C c, PP p)
{
	double L = vabs(vsub(c.p, p));
	double M = sqrt(L*L - c.r* c.r);
	double theta = asin(c.r / L);
	PP v = vsmul(vsub(c.p, p), 1/L);
	PP a = vset(cos(theta), sin(theta)), b = vset(cos(theta), -sin(theta));
	ln->s = vadd(p, vsmul(vmul(v, a), M));
	ln->e = vadd(p, vsmul(vmul(v, b), M));
}

void outer_tangent_parallelLC(LINE *ln1, LINE *ln2, C c1, C c2)
{
	PP d = vsub(c1.p, c2.p);
	PP v = vsmul(vmul(d, vset(0, 1)), c1.r / vabs(d));
	ln1->s = vadd(c1.p, v), ln1->e = vadd(c2.p, v);
	ln2->s = vsub(c1.p, v), ln2->e = vsub(c2.p, v);
}
 
void inner_tangentLC(LINE *ln1, LINE *ln2, C c1, C c2)
{
	PP d, base;	double f; LINE t;

	if (c1.r > c2.r) { inner_tangentLC(ln1, ln2, c2, c1); return; }
	d = vsub(c2.p, c1.p);
	f = c2.r / c1.r + 1;
	base = vadd(c1.p, vsmul(d, 1/f));
	tangentLP(&t, c1, base);
	lset(ln1, base, t.s), lset(ln2, base, t.e);
}

void outer_tangentLC(LINE *ln1, LINE *ln2, C c1, C c2)
{
	PP d, base;	double f; LINE t;

	if (!dcmp(c1.r - c2.r))	{ outer_tangent_parallelLC(ln1, ln2, c1, c2); return; }
	if (c1.r > c2.r) { outer_tangentLC(ln1, ln2, c2, c1); return; }
	d = vsub(c1.p, c2.p);
	f = c2.r / c1.r - 1;
	base = vadd(vadd(c2.p, d), vsmul(d, 1/f));
	tangentLP(&t, c1, base);
	lset(ln1, base, t.s), lset(ln2, base, t.e);
}

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	if (c == '-') {
		c = getchar_unlocked();
		do n = 10*n + (c & 0xf), c = getchar_unlocked();
		while (c >= '0');
		return -n;
	}
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

typedef struct { C c; int m; } JEWEL;
JEWEL jewel[52];

int main()
{
	int N, i, j, f, ans;
	double d;

	while (N = in()) {
		sc = 0; for (i = 0; i < N; i++) {
			int x = in(), y = in(), r = in(), m = in();
			jewel[i].c.p.x = x, jewel[i].c.p.y = y, jewel[i].c.r = r, jewel[i].m = r+m; 
			c[sc].p.x = x, c[sc].p.y = y, c[sc++].r = r;
			if (m > 0) c[sc].p.x = x, c[sc].p.y = y, c[sc++].r = r + m;
		}

		sl = 0;
		for (i = 0; i < sc; i++) for (j = i+1; j < sc; j++) if (i != j) {
			if (PPeQ(c[i].p, c[j].p)) continue;

			if (is_interCC(c[i], c[j])) {
				outer_tangentLC(&line[sl], &line[sl+1], c[i], c[j]), sl += 2;
//				intersectCC(&line[sl].s, &line[sl].e, c[i], c[j]), sl++;
			} else {
				inner_tangentLC(&line[sl], &line[sl+1], c[i], c[j]), sl += 2;
				outer_tangentLC(&line[sl], &line[sl+1], c[i], c[j]), sl += 2;
			}
		}

		ans = 1;
		for (i = 0; i < sl; i++) {
			f = 0;
			for (j = 0; j < N; j++) {
				d = distanceLC(line[i], jewel[j].c);
				if ((EQ(d, jewel[j].c.r) || d >= jewel[j].c.r) &&
					(EQ(d, jewel[j].m) || d <= jewel[j].m)) f++;
			}
			if (f > ans) ans = f;
		}
		printf("%d\n", ans);
	}
	return 0;
}
