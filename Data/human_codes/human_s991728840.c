// AOJ 1341 Longest Chain
// 2018.3.20 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 高速数値入出力
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

#define MAX 1000000
typedef struct { int x, y, z, id; } T;
T t[300005], s[300005];
int dp[300005];
int c[2][1000005];
int m, n;
int a, b, C = ~(1 << 31), M = (1 << 16) - 1;

#define lowbit(x) (x & (-x))
void update(int f, int x, int v)
{
	while (x <= MAX) {
		if (c[f][x] < v) c[f][x] = v;
		x += lowbit(x);
	}
}

int getmax(int f, int x)
{
	int a = 0;
	while (x > 0) {
		if (a < c[f][x]) a = c[f][x];
		x -= lowbit(x);
	}
	return a;
}

void clear(int f, int x)
{
	while (x <= MAX) {
		c[f][x] = 0;
		x += lowbit(x);
	}
}

int cmp2(const void *a, const void *b)
{
	int t = ((T *)a)->y - ((T *)b)->y; if (t) return t;
	return ((T *)b)->z - ((T *)a)->z;
}

void cdq(int l, int r)
{
	int i, k, a, tx, m;

	if (l == r) { if (dp[l] == 0) dp[l] = 1; return; }
	m = (l + r) >> 1;
	tx = t[m + 1].x;
	cdq(l, m);
	k = 0;  for (i = l; i <= r; i++) s[k] = t[i], s[k++].id = i;
	qsort(s, k, sizeof(T), cmp2);
	for (i = 0; i < k; i++) {
		if (s[i].id <= m) {
			update(1, s[i].z, dp[s[i].id]);
			if (s[i].x != tx) update(0, s[i].z, dp[s[i].id]);
		}
		else
		{
			if (s[i].x == tx) a = getmax(0, s[i].z - 1);
			else a = getmax(1, s[i].z - 1);
			if (dp[s[i].id] < a + 1) dp[s[i].id] = a + 1;
		}
	}
	for (i = 0; i < k; i++) {
		if (s[i].id <= m) {
			clear(1, s[i].z);
			if (s[i].x != tx) clear(0, s[i].z);
		}
	}
	cdq(m + 1, r);
}

int r()
{
	a = 36969 * (a & M) + (a >> 16);
	b = 18000 * (b & M) + (b >> 16);
	return (C & ((a << 16) + b)) % MAX;
}

int cmp(const void *a, const void *b) { return ((T *)a)->x - ((T *)b)->x; }

int main()
{
	int i, ans;

	while (1) {
		m = in(), n = in() + m;
		if (m + n == 0) break;
		a = in(), b = in();
		for (i = 1; i <= m; i++) t[i].x = in() + 1, t[i].y = in() + 1, t[i].z = in() + 1;
		for (; i <= n; i++) t[i].x = r() + 1, t[i].y = r() + 1, t[i].z = r() + 1;
		qsort(t + 1, n, sizeof(T), cmp);
		memset(c, 0, sizeof(c));
		memset(dp, 0, sizeof(dp));
		cdq(1, n);
		ans = 0; for (i = 1; i <= n; i++) if (dp[i] > ans) ans = dp[i];
		printf("%d\n", ans);
	}
	return (0);
}

