// AOJ 2804 Minimum Enclosing Rectangle
// 2018.5.5 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { int x, y; } PP;

#define INF 1e18

#define MAX_N 100002
int xpos[MAX_N], ypos[MAX_N];
PP  pi[MAX_N<<2], po[MAX_N<<2]; int sz;

int cmp(PP *a, PP *b) {
	if (a->y - b->y) return a->y - b->y;
	return a->x - b->x;
}

PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
long long cross(PP a, PP b) { return (long long)a.x * b.y - (long long)a.y * b.x; }
int convex_hull(int n, PP *ps, PP *po)
{
	int i, k, j = 0;

	qsort(ps, n, sizeof(PP), cmp);
	for (i = 0; i < n; i++) {
		while (j > 1 && cross(vsub(po[j-1], po[j-2]), vsub(ps[i], po[j-1])) <= 0) j--;
		po[j++] = ps[i];
	}
	k = j;
	for (i = n - 2; i >= 0; i--) {
		while (j > k && cross(vsub(po[j-1], po[j-2]), vsub(ps[i], po[j-1])) <= 0) j--;
		po[j++] = ps[i];
	}
	return j-1;
}

#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()
{
	int n = 0, c = gc();
	do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

void xypos(int id, int x, int y)
{
	xpos[id] = x, ypos[id] = y;
	pi[sz].x = x  , pi[sz].y = y,   sz++;
	pi[sz].x = x+1, pi[sz].y = y,   sz++;
	pi[sz].x = x,   pi[sz].y = y+1, sz++;
	pi[sz].x = x+1, pi[sz].y = y+1, sz++;
}

int main()
{
	int N, n, i, j, d, x, y;
	double delta, ans;
	double t, fx, fy, xmin, xmax, ymin, ymax, cosv, sinv;

	sz = 0;
	xypos(0, 0, 0);
	N = in();
	for (i = 1; i < N; i++) {
		n = in(), d = gc() & 0xf, gc();
		x = xpos[n], y = ypos[n];
		if      (d == 0) xypos(i, x-1, y);	// 左
		else if (d == 1) xypos(i, x, y+1);  // 下
		else if (d == 2) xypos(i, x+1, y);  // 右
		else             xypos(i, x, y-1);  // 上
	}

	n = convex_hull(sz, pi, po);
	po[n] = po[0];

	ans = INF;
	for (i = 0; i < n; i++) {
		delta = -atan2(po[i+1].y-po[i].y, po[i+1].x-po[i].x);
		cosv = cos(delta), sinv = sin(delta);
		x = po[i].x, y = po[i].y;
		xmin = ymin = INF, xmax = ymax = -INF;
		for (j = 0; j < n; j++) {
			fx = (po[j].x-x) * cosv - (po[j].y-y) * sinv;
			fy = (po[j].x-x) * sinv + (po[j].y-y) * cosv;
			if (fx < xmin) xmin = fx;
			if (fx > xmax) xmax = fx;
			if (fy < ymin) ymin = fy;
			if (fy > ymax) ymax = fy;
		}
		t = (xmax-xmin)*(ymax-ymin);
		if (t < ans) ans = t;
	}
	printf("%.10lf\n", ans);
	return 0;
}

