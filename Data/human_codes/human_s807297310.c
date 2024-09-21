// AOJ 1514 Balloon Contest
// 2019.4.1 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//// 高速入力
#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()  // 非負整数の入力
{
	int n = 0, c = gc();
	while (isspace(c)) c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}


//// 計算幾何
#define EPS 1e-8

typedef struct { double x, y; } PP;
typedef struct { PP s, e; } LINE;

PP vset(double x, double y) { PP r; r.x = x, r.y = y; return r; }

int dcmp(double x) {
	if (fabs(x) < EPS) return 0;
	return x < 0 ? -1 : 1;
}

double cross(double ax, double ay, double bx, double by) { return ax * by - ay * bx; }

void lineIntersection(PP *p, LINE *a, PP *vs, PP *ve)
{
	double a1, a2;

	a1 = cross(ve->x - vs->x, ve->y - vs->y,
		a->s.x - vs->x, a->s.y - vs->y);
	a2 = cross(ve->x - vs->x, ve->y - vs->y,
		a->e.x - vs->x, a->e.y - vs->y);
	p->x = (a->s.x*a2 - a->e.x*a1) / (a2 - a1);
	p->y = (a->s.y*a2 - a->e.y*a1) / (a2 - a1);
}

// 凸多角形のカット
int convex_cut(LINE *u, int n, PP *p, PP *po)
{
	int i, d1, d2, top = 0;

	for (i = 0; i < n; i++) {
		d1 = dcmp(cross(u->e.x - u->s.x, u->e.y - u->s.y,
			p[i].x - u->s.x, p[i].y - u->s.y));
		d2 = dcmp(cross(u->e.x - u->s.x, u->e.y - u->s.y,
			p[i + 1].x - u->s.x, p[i + 1].y - u->s.y));
		if (d1 >= 0) po[top++] = p[i];
		if (d1*d2 < 0) lineIntersection(po + top++, u, p + i, p + i + 1);
	}
	po[top].x = po[0].x, po[top].y = po[0].y;
	return top;
}

// 垂直二等分線
void bisector(LINE *u, PP a, PP b)
{
	double ax = (a.x + b.x) / 2;
	double ay = (a.y + b.y) / 2;
	u->s.x = ax, u->s.y = ay;
	if (fabs(a.y - b.y) <= EPS) u->e.x = ax, u->e.y = ay + (b.x - a.x) * 100;
	else u->e.x = ax - (b.y - a.y) * 100, u->e.y = (ax - u->e.x)*(b.x - a.x) / (b.y - a.y) + ay;
}

// ２つの多角形の共通部分（多角形になる）
int insectPoly(PP *ans, int n, PP *poly, int m, PP *cut)
{
	int i, k, k1, k2;
	PP tmp[2][200];
	LINE u;

	k = n, k1 = 0, k2 = 1;
	memcpy(tmp[0], poly, sizeof(PP)*(n+1));
	for (i = 0; i < m; i++) {
		u.s = cut[i], u.e = cut[i + 1];
		k = convex_cut(&u, k, tmp[k1], tmp[k2]);
		k1 = k2, k2 = !k2;
	}
	memcpy(ans, tmp[k1], sizeof(PP)*(k + 1));
	return k;
}

// 多角形の面積
double polygonArea(int n, PP *p)
{
	double area = 0;
	for (int i = 1; i < n - 1; i++) {
		area += cross(p[i].x - p[0].x, p[i].y - p[0].y, p[i + 1].x - p[0].x, p[i + 1].y - p[0].y);
	}
	return fabs(area) / 2;
}


//// 本問題関連
#define INF 20000.0
PP man[105]; int N;
PP poly[105][200]; int nPoly[105];
PP land[5], ball[5];
double val[105];

int main()
{
	int i, j, k, k1, k2, M;
	int x, y, dx, dy, score;
	PP tmp[2][200];
	LINE u;
	double a, ans;

	// 土地全体の座標設定
	land[0] = vset(INF, INF), land[1] = vset(-INF, INF);
	land[2] = vset(-INF, -INF), land[3] = vset(INF, -INF);
	land[4] = land[0];

	while (N = in()) {
		M = in();

		// 参加者のいる場所
		for (i = 0; i < N; i++) man[i].x = in(), man[i].y = in();
		man[N] = man[0];

		// それぞれの参加者がボールを取得できる領域（ボロノイ領域）
		for (i = 0; i < N; i++) {
			memcpy(tmp[0], land, sizeof(land));
			k = 4, k1 = 0, k2 = 1;
			for (j = 0; j < N; j++) {
				if (j == i) continue;
				bisector(&u, man[i], man[j]);
				k = convex_cut(&u, k, tmp[k1], tmp[k2]);
				k1 = k2, k2 = !k2;
			}
			nPoly[i] = k;
			memcpy(poly[i], tmp[k1], sizeof(PP)*(k+1));
		}

		memset(val, 0, sizeof(val[0])*N);
		for (i = 0; i < M; i++) {		// ぞれぞれのボールに対して
			// ボールの落下範囲
			x = in(), y = in(), dx = in(), dy = in(), score = in();
			ball[0] = vset(x + dx, y + dy), ball[1] = vset(x - dx, y + dy);
			ball[2] = vset(x - dx, y - dy), ball[3] = vset(x + dx, y - dy);
			ball[4] = ball[0];

			for (j = 0; j < N; j++) {
				// 各参加者とボールとの共通面積
				k = insectPoly(tmp[0], nPoly[j], poly[j], 4, ball);
				if (k < 3) continue;
				a = polygonArea(k, tmp[0]);
				val[j] += score * a / (4.0*dx*dy);  // 期待値は面積の比に比例
			}
		}

		// 最大期待値が問題の解答
		ans = 0;
		for (i = 0; i < N; i++) if (val[i] > ans) ans = val[i];
		printf("%.12lf\n", ans);
	}
	return 0;
}
