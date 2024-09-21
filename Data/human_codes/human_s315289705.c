// AOJ 2531 Avant-garde Art
// 2018.2.9 bal4u

#include <stdio.h>
#include <string.h>

#define INF 0x30303030
int a[8002];
int dp[8002];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int bsch(int x, int r)
{
	int m, l = 0;

    while (l < r) {
        m = l+((r-l)>> 1);
        if (dp[m] < x) l = m + 1; else r = m;
    }
	return l;
}

int main()
{
	int n, k, i, j, f, t, ans;

	n = in(), k = in();
	for (i = 0; i < n; i++) a[i] = in();

	ans = 0;
	for (i = 0; i < n; i++) {
		f = 0, memset(dp, INF, a[i]<<2);
		for (j = i; j < a[i]; j++) {
			if (a[i] >= a[j]) continue;
			t = bsch(a[j], f+1);
			dp[t++] = a[j];
			if (f < t) f = t;
		}
		f++;
		if (ans < f) ans = f;
	}
	ans += k; if (ans > n/2) ans = n/2;
	printf("%d\n", ans);
	return 0;
}
