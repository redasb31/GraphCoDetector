// AOJ 2928 Mail Order
// 2019.4.5 bal4u

#include <stdio.h>
#include <stdlib.h>

//// 高速入力
#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

int H, W;
int _a[100005];
int _b[100005];
int *a, *b;
long long s[100005];

int upper_bound(int x)
{
	int m, l = 0, r = W;

	while (l < r) {
		m = (l + r) >> 1;
		if (b[m] == x) return m;
		if (b[m] < x) l = m + 1; else r = m;
	}
	return l - 1;
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main()
{
	int i, k, t;
	long long ans;

	H = in(), W = in();
	for (i = 0; i < H; i++) _a[i] = in();
	for (i = 0; i < W; i++) _b[i] = in();
	if (H > W) t = H, H = W, W = t, a = _b, b = _a;  // 短い方を H, a[] にする
	else a = _a, b = _b;
	qsort(b, W, sizeof(int), cmp);
	for (i = 0; i < W; i++) s[i + 1] = s[i] + b[i];  // 累計和

	ans = 0; for (i = 0; i < H; i++) {
		k = upper_bound(a[i]);   // バイナリサーチでa[i]を超えない最大値のindexを得る
		ans += s[k + 1] + (long long)(W - k - 1)*a[i];
	}
	printf("%lld\n", ans);
	return 0;
}
