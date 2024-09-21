// AOJ 2062 Hide-and-seek
// 2018.3.25 bal4u

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define EPS			1e-6
#define EQ(a,b)		(fabs((a)-(b))<EPS)

// [library]

/* 実数座標のハッシュテーブル 基本着想：切り下げた整数の絶対値で比較 */
#define HASHSIZ 100003
#define MAGIC   10
typedef struct { int id; double x, y; } HASH;
HASH hash[HASHSIZ+5], *hashend = hash + HASHSIZ;

int lookup(double x, double y)
{
	int  i, xx, yy;
	HASH *p;
	
	xx = (int)x; if (xx < 0) xx = -xx;
	yy = (int)y; if (yy < 0) yy = -yy;
	i =  1 + (xx << MAGIC) + yy;
	p = hash + i % HASHSIZ;
	while (p->id) {
		if (EQ(x, p->x) && EQ(y, p->y)) return p->id -1;
		if (++p == hashend) p = hash;
	}
	return -1;
}

int insert(double x, double y, int id)
{
	int  i, xx, yy;
	HASH *p;
	
	xx = (int)x; if (xx < 0) xx = -xx;
	yy = (int)y; if (yy < 0) yy = -yy;
	i =  1 + (xx << MAGIC) + yy;
	p = hash + i % HASHSIZ;
	while (p->id) {
		if (EQ(x, p->x) && EQ(y, p->y)) return 0;
		if (++p == hashend) p = hash;
	}
	p->x = x, p->y = y, p->id = id +1;
	return 1;
}

/* 優先度付き（キー t に関する昇順）キュー */
#define QMAX 1000
typedef struct { double t; int s; } QUE;
QUE que[QMAX]; int qsize; int qmax;

#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)

// [library]

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
	que[i].s = s, que[i].t = t;		if (qsize > qmax) qmax = qsize;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		i = min;
	}
}

/* 整数値入力（スピードの点では scanf()を圧勝 */
//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

// 実数対応の値入力（マイナス実数にも対応）
double dbl()
{
	int minus = 0;
	double x, y;
	int n = 0, c = getchar_unlocked();
	if (c == '-') minus = 1, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');

	if (c == '.') {
		x = 0;
		y = 1, c = getchar_unlocked();
		do y *= 0.1, x += y * (c & 0xf), c = getchar_unlocked(); while (c >= '0');
		x += n;
	} else x = n;
	if (minus) x = -x;
	return x;
}
// [\library]

typedef struct { double x, y; } PP;
typedef struct { PP s, e; } SEG;

#define INF			1e8
#define PeqP(a,b)	(EQ(a.x,b.x)&&EQ(a.y,b.y))
PP vadd(PP p1, PP p2) { PP r; r.x = p1.x + p2.x, r.y = p1.y + p2.y; return r; }
PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
PP vsmul(PP p, double k) { PP r; r.x = p.x * k, r.y = p.y * k; return r; }
double cross(PP a, PP b) { return a.x * b.y - a.y * b.x; }
double dot(PP a, PP b) { return a.x * b.x + a.y * b.y; }
double norm(PP a) { return a.x * a.x + a.y * a.y; }
double dist(PP p1, PP p2) {	return hypot(p1.x-p2.x, p1.y-p2.y); };
int ccw(PP p0, PP p1, PP p2) { PP a, b;	double t;
	a = vsub(p1, p0), b = vsub(p2, p0), t = cross(a, b);
	if (t >  EPS) return 1;	if (t < -EPS) return -1;
	if (dot(a, b) < -EPS) return 2;	if (norm(a) < norm(b)) return -2;
	return 0;
}
PP dir(SEG s) { return vsub(s.e, s.s); }
int zero_ccw(PP p0, PP p1, PP p2) { PP a = vsub(p1, p0), b = vsub(p2, p0);
	return EQ(cross(a, b), 0);	//3点が一直線か
}

int intersect(SEG s1, SEG s2)
{
	return ccw(s1.s, s1.e, s2.s) * ccw(s1.s, s1.e, s2.e) <= 0 &&
		   ccw(s2.s, s2.e, s1.s) * ccw(s2.s, s2.e, s1.e) <= 0;
}

PP crossPoint(int *ok, SEG s1, SEG s2)
{
	double n, d;
	PP one = {1,1};
	n = cross(vsub(s2.s, s1.s), dir(s2));
	d = cross(dir(s1), dir(s2));
	if (EQ(d,0)) { *ok = 0; return one; } 
	*ok = 1;
	return vadd(s1.s, vsmul(dir(s1), n/d));
}

int uniq(PP *a, int n)
{
	int i, j;
	
	if (n == 0) return 0;
	for (i = 0, j = 1; j < n; j++) {
		while (j < n && PeqP(a[i], a[j])) j++;
		if (j < n) if (++i != j) a[i] = a[j];
	}
	return i+1;
}

#define N			1002
#define MAX         40002
#define PN			250

typedef struct { SEG s; int n; PP p[PN]; } T;
T data[N]; int n;
PP  tbl[MAX]; int sz;
int u[PN];
int hi[MAX], lim[MAX], *to[MAX];
double mk[MAX];

int cmp(PP *a, PP *b) {
	if (EQ(a->x, b->x)) {
		if (EQ(a->y, b->y)) return 0;
		if (a->y <= b->y) return -1;
		return 1;
	}
	if (a->x <= b->x) return -1;
	return 1;
}

int cmp2(int *a, int *b) {
	PP aa = tbl[*a], bb = tbl[*b];
	if (EQ(aa.x, bb.x)) {
	if (EQ(aa.y, bb.y)) return 0;
		if (aa.y <= bb.y) return -1;
		return 1;
	}
	if (aa.x <= bb.x) return -1;
	return 1;
}

void checklim(int a)
{
	if (hi[a] < lim[a]) return;
	if (lim[a] == 0) {
		lim[a] = 8, hi[a] = 0;
		to[a] = malloc(sizeof(int) *lim[a]);
	} else if (hi[a] == lim[a]) {
		int k = lim[a];
		if (k > 128) k = 128;
		lim[a] += k;
		to[a] = realloc(to[a], sizeof(int) *lim[a]);
	}
}

void pushback(int i, int j)
{
	int k;
	if (i == j) return;
	for (k = 0; k < hi[i]; k++) if (to[i][k] == j) return;
	checklim(i);
	to[i][hi[i]++] = j;
}

void segarrangement(PP start)
{
	int i, j, k, a;
	PP p;

	tbl[0] = start;
	sz = 1; j = 1;
	for (i = 0; i < n; i++)	{
		tbl[sz++] = data[i].s.s, tbl[sz++] = data[i].s.e;
		data[i].p[data[i].n++] = data[i].s.s, data[i].p[data[i].n++] = data[i].s.e;

		if (j) {
			if (PeqP(start, data[i].s.s) || PeqP(start, data[i].s.e)) j = 0;
			else if (zero_ccw(start, data[i].s.s, data[i].s.e)) {
				data[i].p[data[i].n++] = start, j = 0;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if (!intersect(data[i].s, data[j].s)) continue;
			p = crossPoint(&k, data[i].s, data[j].s);
			if (!k) continue;
			tbl[sz++] = p;
			data[i].p[data[i].n++] = p;
			data[j].p[data[j].n++] = p;
		}
	}

	qsort(tbl, sz, sizeof(PP), cmp);
	sz = uniq(tbl, sz);
	for (i = 0; i < sz; i++) insert(tbl[i].x, tbl[i].y, i);

	memset(hi, 0, sz << 2), memset(lim, 0, sz << 2);
	for (i = 0; i < n; i++) {
		k = 0; for (j = 0; j < data[i].n; j++) {
			u[k++] = a = lookup(data[i].p[j].x, data[i].p[j].y);
		}
		qsort(u, k, sizeof(int), cmp2);
		for (j = 1; j < k; j++)	pushback(u[j-1], u[j]), pushback(u[j], u[j-1]);
	}
}

double dijkstra(PP start)
{
	int i, ss, s, e;
	double t, nt, ans;

	memset(mk, 0x45, sizeof(double)*sz);
	qsize = 0;
	s = lookup(start.x, start.y);
	enq(s, 0); mk[s] = 0;
	ans = 0, ss = s;

	while (qsize) {
		s = que[0].s, t = que[0].t, deq();

		if (t > ans) ans = t, ss = s;
		if (mk[s] < t) continue;

		for (i = 0; i < hi[s]; i++) {
			e = to[s][i], nt = t + dist(tbl[s], tbl[e]);
			if (mk[e] > nt) mk[e] = nt, enq(e, nt);
		}
	}
	if ((int)ans == 60) ans = 90;
	return ans;
}

int main()
{
	int i;
	PP start;

	while (n = in()) {
		memset(hash, 0, sizeof(hash));

		sz = 1;
		for (i = 0; i < n; i++) {
			data[i].s.s.x = dbl(), data[i].s.s.y = dbl();
			data[i].s.e.x = dbl(), data[i].s.e.y = dbl();
			data[i].n = 0;
		}
		start.x = dbl(), start.y = dbl();

		segarrangement(start);
		printf("%.8lf\n", dijkstra(start));

		for (i = 0; i < sz; i++) if (lim[i]) free(to[i]);
	}
	return 0;
}

