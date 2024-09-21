// AOJ 1183 Chain-Confined Path
// 2018.3.7 bal4u

#include <stdio.h>
#include <string.h>
#include <math.h>

#define QMAX 1000
typedef struct { int s; double t; } QUE;
QUE que[QMAX]; int qsize;

#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)

void min_heapify(int i)
{
	int l, r, min;
	QUE qt;

	l = LEFT(i), r = RIGHT(i);
	if (l < qsize && que[l].t < que[i].t) min = l; else min = i;
	if (r < qsize && que[r].t < que[min].t) min = r;
	if (min != i) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		min_heapify(min);
	}
}

void deq()
{
	que[0] = que[--qsize];
	min_heapify(0);
}

void enq(int s, double t)
{
	int i, min;
	QUE qt;

	i = qsize++;
	que[i].s = s, que[i].t = t;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		i = min;
	}
}

typedef struct { double x, y; } PP;
typedef struct { PP s, e; } SEG;
typedef struct { double x, y, r; } C;

#define EPS 1e-8
#define EQ(a,b)		(fabs((a)-(b))<EPS)
PP d2p(double x, double y) { PP r; r.x = x, r.y = y; return r; }
PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
double cross(PP a, PP b) { return a.x * b.y - a.y * b.x; }
double dot(PP a, PP b) { return a.x * b.x + a.y * b.y; }
double norm(PP a) { return a.x * a.x + a.y * a.y; }
double vabs(PP a) { return hypot(a.x, a.y); }
double dist(PP p1, PP p2) {	return vabs(vsub(p1, p2)); }
void p2v(SEG *s, PP p1, PP p2) { s->s = p1, s->e = p2; } 
int ccw(PP p0, PP p1, PP p2) { PP a, b;	double t;
	a = vsub(p1, p0), b = vsub(p2, p0), t = cross(a, b);
	if (t >  EPS) return 1;	if (t < -EPS) return -1;
	if (dot(a, b) < -EPS) return 2;	if (norm(a) < norm(b)) return -2;
	return 0;
}

int intersectSS(SEG s1, SEG s2)
{
	return ccw(s1.s, s1.e, s2.s) * ccw(s1.s, s1.e, s2.e) <= 0 &&
		   ccw(s2.s, s2.e, s1.s) * ccw(s2.s, s2.e, s1.e) <= 0;
}

int intersectCC(C c1, C c2, PP *p1, PP *p2)
{
	double x1 = c1.x, y1 = c1.y, r1 = c1.r;
	double x2 = c2.x, y2 = c2.y, r2 = c2.r;
	double d = dist(d2p(x1, y1), d2p(x2, y2));
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

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

C c[102];
SEG a[102];
PP p[202]; int sz;
int hi[402], to[402][402];
char mk[202];

double dijkstra(int start, int goal)
{
	int i, s, e;
	double d;

	memset(mk, 0, sizeof(mk));
	qsize = 0; d = 0;
	enq(start, 0);
	while (qsize) {
		s = que[0].s, d = que[0].t, deq();
		if (s == goal) break;
		if (mk[s]) continue;
		mk[s] = 1;
		for (i = 0; i < hi[s]; i++) {
			e = to[s][i];
			if (mk[e]) continue;
			enq(e, d + dist(p[s], p[e]));
		}
	}
	return d;
}

int check(int p1, int p2, int s1, int s2)
{
	int i; SEG s;
	p2v(&s, p[p1], p[p2]);
	for (i = s2; i >= s1; i--) if (!intersectSS(s, a[i])) return 0;
	return 1;
}

int main()
{
	int n, i, j, ii, jj;

	while (n = in()) {
		for (i = 0; i < n; i++) c[i].x = in(), c[i].y = in(), c[i].r = in();
		p[0] = d2p(c[0].x, c[0].y), sz = 1;
		for (i = 1; i < n; i++) {
			intersectCC(c[i-1], c[i], &a[i].e, &a[i].s);
			p[sz++] = a[i].s, p[sz++] = a[i].e;
		}
		p[sz++] = d2p(c[n-1].x, c[n-1].y);

		if (check(0, sz-1, 1, n-1)) { printf("%lf\n", dist(p[0], p[sz-1])); continue; }

		memset(hi, 0, sizeof(hi));
		for (i = 0; i < sz; i++) {
			ii = (i+1) >> 1;
			for (j = sz-1; j > i; j--) {
				jj = (j+1) >> 1;
				if (ii == jj) break;
				if (check(i, j, ii+1, jj-1)) to[i][hi[i]++] = j;
			}
		}

		printf("%lf\n", dijkstra(0, sz-1));
	}
	return 0;
}
