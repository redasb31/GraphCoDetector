// AOJ 1254 Color the Map
// 2018.3.19 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 高速数値出力
#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
// 整数（負数も）の入力
int in()
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

// 文字列の入力　スペース以下の文字で入力終了
void ins(char *s)
{
	do *s = gc();
	while (*s++ > ' ');
	*(s - 1) = 0;
}


// 文字列のハッシュ関数
#define HASHSIZ 997
typedef struct { char *s; int id; } HASH;
HASH hash[HASHSIZ + 2], *hashend = hash + HASHSIZ;

int insert(char *s, int id)
{
	unsigned long long i;
	int j;
	char *p;
	HASH *tp;

	i = 0, p = s;
	for (j = 0; *p && j < 12; j++) i = (i << 5) + (*p++ + 1 - 'a');
	tp = hash + (int)(i % HASHSIZ);
	while (tp->s != NULL) {
		if (!strcmp(tp->s, s)) return tp->id;
		if (++tp == hashend) tp = hash;
	}
	tp->s = s, tp->id = id;
	return -1;
}


// 平面幾何関連    座標を整数に修正したので、実用性ゼロ
typedef struct { int x, y; } PP;
typedef struct { PP s, e; } SEG, LINE;
typedef struct { int n; PP p[105]; } POLY;   // 多角形に含まれる最大頂点 50

#define INF			100000000
#define EQ(a,b)		((a)==(b))
#define PPeQ(a,b)	(EQ(a.x,b.x)&&EQ(a.y,b.y))

int ppInSeg(PP p, PP p1, PP p2)
{
	int x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;
	int d;
	if (x1 > x2) { d = x1, x1 = x2, x2 = d; d = y1, y1 = y2, y2 = d; }
	d = (x1 <= p.x && p.x <= x2 &&
		((y1 <= y2 && y1 <= p.y && p.y <= y2) ||
		(y1 > y2 && y2 <= p.y && p.y <= y1))
		&& (p.y - y1)*(x2 - x1) == (y2 - y1)*(p.x - x1));
	if (!d || PPeQ(p, p1) || PPeQ(p, p2)) return 0;
	return 1;
}

// ２本の直線は平行しているか
int isParaLL(PP s1s, PP s1e, PP s2s, PP s2e) {
	return EQ((s2e.y - s2s.y)*(s1e.x - s1s.x),
		      (s1e.y - s1s.y)*(s2e.x - s2s.x));
}

// 2本の線分は重なっているか
int overlapSS(PP s1s, PP s1e, PP s2s, PP s2e)
{
	if (!isParaLL(s1s, s1e, s2s, s2e)) return 0;
	return ppInSeg(s1s, s2s, s2e) || ppInSeg(s1e, s2s, s2e) ||
		   ppInSeg(s2s, s1s, s1e) || ppInSeg(s2e, s1s, s1e) ||
           (PPeQ(s1s, s2s) && PPeQ(s1e, s2e)) || (PPeQ(s1s, s2e) && PPeQ(s1e, s2s));
}

// ２つの多角形が隣接（頂点ではなく、線分でオーバラップしているか）
int intersectPoly(int n1, PP *p1, int n2, PP *p2)
{
	int i, j;

	for (i = 0; i < n1; i++)
		for (j = 0; j < n2; j++)
			if (overlapSS(p1[i], p1[i + 1], p2[j], p2[j + 1])) return 1;
	return 0;
}


// 本問題関連
typedef struct { int id, hi; } T;
T t[13];
int N;
POLY poly[105];
char name[105][25]; int id[105]; int sz;
int adj[13][50], hi[13];
int color[13];

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int cmp2(const void *a, const void *b) { return ((T *)b)->hi - ((T *)a)->hi; }

int check(int id, int max)
{
	int i, k;
	char f[13];

	if (id >= sz) return 1;
	memset(f, 0, sizeof(f));
	for (i = 0; i < hi[id]; i++) {
		k = color[adj[id][i]];
		if (k) f[k] = 1;
	}
	for (i = 1; i <= max; i++) if (!f[i]) {
		color[id] = i;
		if (check(id + 1, max)) return 1;
		color[id] = 0;
	}
	return 0;
}

int main()
{
	int i, j, k, x, ans;
	int id1, id2;
	char f[13];

	while (N = in()) {
		memset(hash, 0, sizeof(hash));
		sz = 0;
		for (i = 0; i < N; i++) {
			ins(name[sz]);
			if ((k = insert(name[sz], sz)) < 0) k = sz++;
			id[i] = k;
			for (j = 0; (x = in()) >= 0; j++)
				poly[i].p[j].x = x, poly[i].p[j].y = in();
			poly[i].n = j;
			poly[i].p[j] = poly[i].p[0];
		}
#if 0
		for (i = 0; i < N; i++) {
			printf("id=%d, n=%d:", id[i], poly[i].n);
			for (j = 0; j < poly[i].n; j++) printf(" (%d,%d)", poly[i].p[j].x, poly[i].p[j].y);
			printf("\n");
		}
#endif
		memset(hi, 0, sizeof(hi));
		x = 0; for (i = 0; i < N; i++) {
			id1 = id[i];
			for (j = i + 1; j < N; j++) {
				id2 = id[j];
				if (id1 == id2) continue;
				for (k = 0; k < hi[id1]; k++) if (adj[id1][k] == id2) break;
				if (k < hi[id1]) continue;
				if (intersectPoly(poly[i].n, poly[i].p, poly[j].n, poly[j].p)) {
					adj[id1][hi[id1]++] = id2;
					adj[id2][hi[id2]++] = id1;
					x++;
				}
			}
		}
#if 0
		for (i = 0; i < sz; i++) {
			printf("adj[%d] ", i);
			for (j = 0; j < hi[i]; j++) printf(" %d", adj[i][j]);
			printf("\n");
		}
#endif
		if (x <= 1) ans = x + 1;
		else {
			for (i = 0; i < sz; i++) t[i].id = i, t[i].hi = hi[i];
			qsort(t, sz, sizeof(T), cmp2);
			memset(color, 0, sizeof(color));
			color[t[0].id] = 1;
			for (i = 1; i < sz; i++) {
				id1 = t[i].id;
				memset(f, 0, sizeof(f));
				for (j = 0; j < hi[id1]; j++) {
					if (color[adj[id1][j]]) f[color[adj[id1][j]]] = 1;
				}
				for (j = 1; f[j]; j++);
				color[id1] = j;
			}
			qsort(color, sz, sizeof(int), cmp);
			ans = 1; for (i = 1; i < sz; i++) {
				if (color[i] != color[i - 1]) ans++;
			}
#if 0
			if (ans > 2) while (1) {
				memset(color, 0, sizeof(color));
				if (!check(0, ans - 1)) break;
				ans--;
			}
#endif
		}
		printf("%d\n", ans);
	}
	return 0;
}

