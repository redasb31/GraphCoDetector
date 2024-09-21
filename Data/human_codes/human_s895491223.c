// AOJ 1588: Potatoes
// 2017.11.29 bal4u@uu

#include <stdio.h>
#include <stdlib.h>

typedef struct { int a, b; } T;
T tbl[16];

int cmp(T *a, T *b) { return b->a - a->a; }

int main() 
{
	int N, M, K, i, j, k;
	int a1, b1, m1, a2, b2, m2, a3, b3, m3, ans;

	scanf("%d%d%d", &N, &M, &K);
	for (i = 0; i < N; i++) scanf("%d", &tbl[i].a);
	for (i = 0; i < N; i++) scanf("%d", &tbl[i].b);
	qsort(tbl, N, sizeof(T), cmp);

	ans = 0;
	for (i = 0; i < N; i++) {
		b1 = tbl[i].b; if (b1 > M) b1 = M;
		m1 = M - b1;
		a1 = tbl[i].a * b1;
		if (K > 1 && m1 > 0) for (j = i+1; j < N; j++) {
			b2 = tbl[j].b; if (b2 > m1) b2 = m1;
			m2 = m1 - b2;
			a2 = tbl[j].a * b2;
			if (K > 2 && m2 > 0) for (k = j+1; k < N; k++) {
				b3 = tbl[k].b; if (b3 > m2) b3 = m2;
				m3 = m2 - b3;
				a3 = tbl[k].a * b3;
				if (a1 + a2 + a3 + m3 > ans) ans = a1 + a2 + a3 + m3;
			} else if (a1 + a2 + m2 > ans) ans = a1 + a2 + m2;
		} else if (a1 + m1 > ans) ans = a1 + m1;
	}
	printf("%d\n", ans);
	return 0; 
}