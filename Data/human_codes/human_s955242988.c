// AOJ 1530 Lonely Adventuer
// 2019.3.24 bal4u

#include <stdio.h>
#include <stdlib.h>

//// 高速入力処理
#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()  // 非負整数の入力
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

//// 本問題関連
int cmp(const void *a, const void *b) {	return *(int *)a - *(int *)b; }
int t[1005], N;

int resolv(int n)
{
	int u, v;
	if (n == 1) return t[0];
	if (n == 2) return t[1];
	if (n == 3) return t[0] + t[1] + t[2];
	u = t[n-1] + t[0] + t[n-2] + t[0];  // (0, n-1)->(0)->(0,n-2)->(0)
	v = t[1] + t[1] + t[n-1] + t[0];    // (0,1)->(1)->(n-2,n-1)->(0)
	if (u > v) u = v;
	return u + resolv(n - 2);
}

int main()
{
	int i;

	N = in();
	for (i = 0; i < N; i++) t[i] = in();
	qsort(t, N, sizeof(t[0]), cmp);
	printf("%d\n", resolv(N));
	return 0;
}
