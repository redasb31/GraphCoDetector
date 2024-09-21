// Aizu 1297: Swimming Jam
// 2017.11.2 bal4u@uu

#include <stdio.h>
#include <stdlib.h>

#define MAX 52
typedef struct { int t, c, a; } T;   // a: arive time
T q[2][MAX+2]; int top[2], end[2];
T p[MAX+2]; int sz;

int cmp(T *a, T *b) { if (a->t - b->t) return a->t - b->t; return b->c - a->c; }

int uniq(int n)
{
	int i, j;
	
	for (i = 0, j = 1; j < n; j++) {
		while (j < n && p[j].t == p[i].t) j++;
		if (j < n) if (++i != j) p[i] = p[j];
	}
	return i+1;
}

int main()
{
	int n, i, j, k, t, a, ans, t1;

    while(scanf("%d", &n) && n > 0) {
		for (i = 0; i < n; i++ ) scanf("%d%d", &p[i].t, &p[i].c), p[i].a = p[i].t;
		qsort(p, n, sizeof(T), cmp);
		n = uniq(n);
		if (n == 1) { printf("%d\n", (p[0].t<<1) * p[0].c); continue; }
		for (i = 0; i < n; i++) q[0][i] = p[i];
		top[0] = top[1] = end[0] = end[1] = 0, end[0] = n;

		ans = 0;
		while (n > 0) {
			j = 0, t = t1 = 0x7fffffff;
			if (top[0] != end[0]) t  = q[0][top[0]].a;
			if (top[1] != end[1]) t1 = q[1][top[1]].a;
			if (t > t1) j = 1, t = t1;

			sz = 0;
			while (top[j] != end[j]) {
				k = top[j];
				a = q[j][k].a;
				if (t < a) break;
				if (j == 1) q[j][k].c--;
				if (!q[j][k].c) n--, ans = t;
				else p[sz] = q[j][k], p[sz].a = t + p[sz].t, sz++; 
				if (++k == MAX) k = 0;
				top[j] = k;
			}
			if (n == 0) break;
			qsort(p, sz, sizeof(T), cmp);

			j = !j, k = end[j];
			for (i = 0; i < sz; i++) {
				q[j][k] = p[i]; if (++k == MAX) k = 0;
			}
			end[j] = k;
		}
		printf("%d\n", ans);
	}
	return 0;
}