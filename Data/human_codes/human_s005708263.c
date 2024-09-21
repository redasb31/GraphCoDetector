// AOJ 1507 Dungeon (II)
// 2018.3.18 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 高速数値入力
#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()  // 非負整数のみ
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

/* UNION-FIND library */
#define MAX 200005
int id[MAX], size[MAX];
void init(int n) { int i; for (i = 0; i < n; i++) id[i] = i, size[i] = 1; }
int root(int i) { while (i != id[i]) id[i] = id[id[i]], i = id[i]; return i; }
int connected(int p, int q) { return root(p) == root(q); }
void unite(int p, int q)
{
	int i = root(p), j = root(q); if (i == j) return;
	if (size[i] < size[j]) id[i] = j, size[j] += size[i]; else id[j] = i, size[i] += size[j];
}

// 本問題関連
typedef struct { int a, b, c; } T;
T t[MAX]; int N;

int cmp(const void *a, const void *b) {	return ((T *)a)->c - ((T *)b)->c; }

int main()
{
	int i, a, b;
	long long ans;

	N = in() - 1;
	for (i = 0; i < N; i++)
		t[i].a = in(), t[i].b = in(), t[i].c = in();
	qsort(t, N, sizeof(T), cmp);
	init(N + 1);
	ans = 0;
	for (i = 0; i < N; i++) {
		a = t[i].a, b = t[i].b;
		ans += (long long)size[root(a)] * size[root(b)] * t[i].c;
		unite(a, b);
	}
	printf("%lld\n", ans);
	return 0;
}
