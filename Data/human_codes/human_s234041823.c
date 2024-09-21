// AOJ 3056 Equilateral Triangle
// 2018.3.15 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()   // 整数の入力（負数に対応）
{
	int n = 0, c = gc();
	if (c == '-') {
		c = gc();
		do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
		return -n;
	}
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

typedef struct { double x, y; } PP;

#define INF			1e16

PP vset(double x, double y) { PP r; r.x = x, r.y = y; return r; }
PP vadd(PP p1, PP p2) { PP r; r.x = p1.x + p2.x, r.y = p1.y + p2.y; return r; }
PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
PP vsmul(PP p, double k) { PP r; r.x = p.x * k, r.y = p.y * k; return r; }
PP vmul(PP p1, PP p2) {
	PP r;
	r.x = p1.x * p2.x - p1.y * p2.y, r.y = p1.x * p2.y + p1.y * p2.x; return r;
}
double dist(PP p1, PP p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

#define TAN30 0.57735026918962576450914878050196

int N;
PP pp[10010];

int main()
{
	int i, j;
	double delta, _sin, _cos, min, max, ans, u, v, t;
	PP q;

	N = in(); ans = INF;
	for (i = 0; i < N; i++) pp[i].x = in(), pp[i].y = in();
	pp[N] = pp[0];
	for (i = 0; i < N; i++) {
		max = min = 0;
		delta = -atan2(pp[i + 1].y - pp[i].y, pp[i + 1].x - pp[i].x);
		_cos = cos(delta), _sin = sin(delta);
		for (j = 1; j < N; j++) {
			q = vsub(pp[(i + j) % N], pp[i]);
			q = vmul(q, vset(_cos, _sin));
			t = fabs(q.y)*TAN30, u = q.x + t, v = q.x - t;
			if (u > max) max = u;
			if (v < min) min = v;
		}
		if (max - min < ans) ans = max - min;
	}
	printf("%.12lf\n", ans);
	return 0;
}
