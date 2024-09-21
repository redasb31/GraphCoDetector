// AOJ 1523 Cone Cut
// 2018.3.20 bal4u

#include <stdio.h>
#include <string.h>
#include <math.h>

#define EPS         1e-7
#define EQ(a,b)     (fabs((a)-(b))<EPS)
#define PI          3.1415926535897932384626433832795

// [library]
typedef struct { double x, y; } PP;
typedef struct { PP s, e; } LINE;
typedef struct { double x, y, r; } C;

PP vset(double x, double y) { PP r; r.x = x, r.y = y; return r; }
double vabs(PP a) { return hypot(a.x, a.y); }
PP vadd(PP p1, PP p2) { PP r; r.x = p1.x + p2.x, r.y = p1.y + p2.y; return r; }
PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
PP vsmul(PP p, double k) { PP r; r.x = p.x * k, r.y = p.y * k; return r; }
double dist(PP p1, PP p2) {	return vabs(vsub(p1, p2)); }
double cross(PP a, PP b) { return a.x * b.y - a.y * b.x; }


// 直線同士の交点
PP crossPointLL(LINE ln1, LINE ln2)
{
	PP u = vsub(ln1.e, ln1.s), v = vsub(ln2.e, ln2.s);
	return vadd(ln1.s, vsmul(u, cross(v, vsub(ln2.s, ln1.s))/cross(v, u)));
}

// 円と円の交点２つ、または１つか、ゼロ
int intersectCC(PP *p1, PP *p2, C c1, C c2)
{
	double x1 = c1.x, y1 = c1.y, r1 = c1.r;
	double x2 = c2.x, y2 = c2.y, r2 = c2.r;
	double d = dist(vset(x1, y1), vset(x2, y2));
	double w, n, x, y, p, q;
	double u, v;

	u = r1+r2, v = fabs(r1-r2);

	if ((fabs(d-u) > EPS && d >= u) || fabs(v-d) > EPS && d <= v) return 0;
	w = ((r1*r1 - r2*r2)/d + d) / 2;
	n = sqrt(r1*r1 - w*w);
	x = x1 + (x2-x1)*w / d;
	y = y1 + (y2-y1)*w / d;
	p = (y2-y1)*n / d;
	q = (x2-x1)*n / d;

	p1->x = x+p, p2->x = x-p;
	p1->y = y-q; p2->y = y+q;
	if (fabs(d-u) <= EPS) return 1;
	if (d == r1+r2) return 1;
	return 2;
}

int Sx, Sy, Sz;          // Apex of the cone: S
int Ox, Oy, Oz, R;
int Px, Py, Pz;

double dist3d(int x1, int y1, int z1, int x2, int y2, int z2)
{
	int dx = x1 - x2;
	int dy = y1 - y2;
	int dz = z1 - z2;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

int main()
{
	double SO, SP, PO, V, ans;
	PP     S, O, A, B, P, a, b;		// a = A', b = B'
	double Sa, Sb, ab;           // Sa = |S-A'|, Sb = |S-B'|, ab = |A'-B'|
	LINE   ln1, ln2;

	scanf("%d%d%d", &Sx, &Sy, &Sz);
	scanf("%d%d%d%d", &Ox, &Oy, &Oz, &R);
	scanf("%d%d%d", &Px, &Py, &Pz);

	SO = dist3d(Sx, Sy, Sz, Ox, Oy, Oz);
	SP = dist3d(Sx, Sy, Sz, Px, Py, Pz);
	PO = dist3d(Px, Py, Pz, Ox, Oy, Oz);
	V = R*R*SO* PI/3;

	O = vset( 0, 0);
	S = vset( 0, SO);
	A = vset(-R, 0);
	B = vset( R, 0);

	if (EQ(SP+PO, SO)) {
		P = vset(0, PO);
	} else {
		C c1, c2; PP p;
		c1.x = 0, c1.y = SO, c1.r = SP;
		c2.x = 0, c2.y = 0,  c2.r = PO;
		intersectCC(&P, &p, c1, c2);
		if (P.x > 0) P.x = -P.x;
	}
	ln1.s = P, ln1.e = B, ln2.s = S, ln2.e = A;
	a = crossPointLL(ln1, ln2);

	ln1.s = P, ln1.e = A, ln2.s = S, ln2.e = B;
	b = crossPointLL(ln1, ln2);

	Sa = dist(S, a);
	Sb = dist(S, b);
	ab = dist(a, b);

	ans = (ab+Sa-Sb)*(ab-Sa+Sb)*sqrt((ab+Sa+Sb)*(Sa+Sb-ab)) * PI/24;

	printf("%lf %lf\n", ans, V-ans);
	return 0;
}
