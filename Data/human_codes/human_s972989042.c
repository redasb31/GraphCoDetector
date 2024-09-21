// AOJ 1581 Reflection Warp Machine
// 2018.3.17 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* UNION-FIND library */
#define MAX 10
int id[MAX], size[MAX];
void init(int n) { int i; for (i = 0; i < n; i++) id[i] = i, size[i] = 1; }
int root(int i) { while (i != id[i]) id[i] = id[id[i]], i = id[i]; return i; }
int connected(int p, int q) { return root(p) == root(q); }
void unite(int p, int q)
{
	int i = root(p), j = root(q); if (i == j) return;
	if (size[i] < size[j]) id[i] = j, size[j] += size[i]; else id[j] = i, size[i] += size[j];
}

typedef struct { double x, y; } PP;
typedef struct { PP s, e; } SEG, LINE;

#define INF			1e8
#define EPS			1e-8
#define EQ(a,b)		(fabs((a)-(b))<EPS)
#define PPeQ(a,b)	(EQ(a.x,b.x)&&EQ(a.y,b.y))

int dcmp(double x) { if (fabs(x) < EPS) return 0; return x <= 0 ? -1 : 1; }
PP vset(double x, double y) { PP r; r.x = x, r.y = y; return r; }
PP vadd(PP p1, PP p2) { PP r; r.x = p1.x + p2.x, r.y = p1.y + p2.y; return r; }
PP vsub(PP p1, PP p2) { PP r; r.x = p1.x - p2.x, r.y = p1.y - p2.y; return r; }
PP vsmul(PP p, double k) { PP r; r.x = p.x * k, r.y = p.y * k; return r; }
PP vmul(PP p1, PP p2) {
	PP r;
	r.x = p1.x * p2.x - p1.y * p2.y, r.y = p1.x * p2.y + p1.y * p2.x; return r;
}

void centerLine(LINE *ln, PP p1, PP p2)  // 両点の間にある直線（対称軸）
{
	PP p = vset(0.5*(p1.x + p2.x), 0.5*(p1.y + p2.y));
	ln->s = p;
	ln->e = vadd(p, vmul(vsub(p, p1), vset(0, 1)));
}

int isParaLL(SEG s1, SEG s2)
{
	if (EQ((s2.e.y - s2.s.y)*(s1.e.x - s1.s.x),
		(s1.e.y - s1.s.y)*(s2.e.x - s2.s.x))) return 1;
	return 0;
}

int identicalLL(LINE ln1, LINE ln2)
{
	LINE l1;
	if (isParaLL(ln1, ln2)) {
		if (PPeQ(ln1.s, ln2.s) || PPeQ(ln1.e, ln2.e)) return 1;
		l1.s = ln1.s, l1.e = ln2.s;
		if (isParaLL(l1, ln1)) return 1;
	}
	return 0;
}

int N;
typedef struct { int n, pp[56]; } T;
T tbl[30];
LINE line[30]; int sz;
PP pp[10];
int r[10];   // 組み合わせ生成用

int cmp(const void *a, const void *b) {	return ((T *)b)->n - ((T *)a)->n; }

int update(LINE ln, int pa, int pb)
{
	int i;
	for (i = 0; i < sz; i++) {
		if (identicalLL(line[i], ln)) {
			tbl[i].pp[tbl[i].n++] = pa, tbl[i].pp[tbl[i].n++] = pb;
			return 0;
		}
	}
	tbl[sz].pp[tbl[sz].n++] = pa, tbl[sz].pp[tbl[sz].n++] = pb;
	line[sz++] = ln;
	return 1;
}

int action(int m)
{
	int i, j, t, ln;

	init(N);
	for (i = 1; i <= m; i++) {
		ln = r[i]-1;
		for (j = 0; j < tbl[ln].n; j += 2) unite(tbl[ln].pp[j], tbl[ln].pp[j + 1]);
	}
#if 0
	printf("sz=%d. m=%d: ", sz, m);
	for (i = 1; i <= m; i++) printf("%d ", r[i] - 1); printf("\n");
	printf("Root: ");
	for (i = 0; i < N; i++) printf(" %d", root(i));
	for (i = 0; i < m; i++) {
		ln = r[i];
		printf(" (%lf,%lf)-(%lf,%lf) ", line[ln].s.x, line[ln].s.y, line[ln].e.x, line[ln].e.y);
	}
	printf("\n");
#endif
	t = root(0);
	for (i = 1; i < N; i++) if (root(i) != t) return 0;
	return 1;
}

int combin(int n, int m)
{
	int i;

	if (n > m) {
		if (action(m)) return 1;
	}
	else for (i = r[n - 1] + 1; i <= sz - m + n; i++) {
		r[n] = i;
		if (combin(n + 1, m)) return 1;
	}
	return 0;
}

int main()
{
	int i, j, l, m, r, f, ans;
	LINE ln;

	scanf("%d", &N);
	ans = N - 1, f = 0;
	if (N > 3) {
		for (i = 0; i < N; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			pp[i].x = x, pp[i].y = y;
		}
		for (i = 0; i < N; i++) {
			for (j = i + 1; j < N; j++) {
				centerLine(&ln, pp[i], pp[j]);
				if (!update(ln, i, j)) f = 1;
			}
		}
		if (f) {
			qsort(tbl, sz, sizeof(T), cmp);
#if 0
			printf("sz=%d\n", sz);
			for (i = 0; i < sz; i++) {
				ln = line[i];
				printf("(%lf,%lf)-(%lf,%lf)  n:%d ", ln.s.x, ln.s.y, ln.e.x, ln.e.y, tbl[i].n);
				for (j = 0; j < tbl[i].n; j += 2) printf("(%d %d) ", tbl[i].pp[j], tbl[i].pp[j + 1]);
				printf("\n");
			}
#endif
			l = 2, r = ans;
			while (l < r) {
				m = (l + r) >> 1;
				if (combin(1, m)) ans = m, r = m;
				else l = m + 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

#if 0
#include <time.h>
int main()
{
	int N = 8, i, x, y;

	printf("%d\n", N);
	srand((unsigned)time(NULL));
	for (i = 0; i < N; i++) {
		x = rand() % 200, y = rand() % 200;
		printf("%d %d\n", x - 100, y - 100);
	}
	return 0;
}

test Sample input 1
8
0 0
0 1
0 2
0 3
0 4
0 5
0 6
0 7

Sample Output 1
2

test Sample input 2
8
100 100
0 100
-100 100
-100 0
-100 -100
0 -100
100 -100
100 0

Sample Output 2
3

test Sample input 3
8
49 -76
89 50
70 -10
-35 58
36 -63
53 57
-34 -8
84 -23

Sample Output 3
7
#endif
