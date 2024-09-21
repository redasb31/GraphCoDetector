// AOJ 2814: Energy Drink
// 2018.1.4 bal4u@uu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x10101010
#define MAX 200002

typedef struct { int a, b; char f; } T;
T t[MAX]; int n;
int dp[MAX];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int cmp(T *a, T *b) { if (a->a - b->a) return a->a - b->a; return b->b - a->b; }

int bsch(int x)
{
	int m, l = 0, r = n;

    while (l < r) {
        m = (l + r) >> 1;
        if (dp[m] < x) l = m + 1; else r = m;
    }
	return l;
}

int main()
{
	int i, a, b, f, sz;

	n = in();
	sz = 0;
	for (i = 0; i < n; i++) {
		a = in(), b = in();
		t[sz].a = a, t[sz++].b = b;
		t[sz].a = b, t[sz].b = a, t[sz++].f = 1;
	}
	n <<= 1; qsort(t, n, sizeof(T), cmp);

	memset(dp, INF, sizeof(dp));
	for (i = 0; i < n; i++) {
		b = t[i].b, f = t[i].f;
		a = bsch(b);
		if ((a & 1) == f) dp[a] = b;
	}
	printf("%d\n", bsch(INF));
	return 0;
}

