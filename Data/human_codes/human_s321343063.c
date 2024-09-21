// AOJ 2787 Pipe Fitter and the Fierce Dogs
// 2018.4.15 bal4u

#include <stdio.h>
#include <string.h>

// バッファを経ずstdinから数値を得る
//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

#define INF 0x10101010
int dp[10002];
char dog[5002][10002];
 
int main()
{
	int W, H, K, N, x, y, s, t, ans;

	W = in(), H = in(), K = in(), N = in();
	H >>= 1;
	K -= (W>>1)+1; if (K < 0) { puts("-1"); return 0; }
	while (N--) {
		x = in()-1, y = in()-1;
		if (y & 1) dog[y>>1][x] = 1;
	}

	s = 0;
	for (y = 0; y < H; y++) {
		memset(dp, INF, (W+1)<<2);
		dp[0] = 0;
		for (x = 0; x < W; x++) {
			if (x & 1) dp[x+1] = dp[x];
			else {
				t = dp[x] + dog[y][x];
				if (dp[x+1] > t) dp[x+1] = t;
				if (x >= 2) {
					t = dp[x-2] + (dog[y][x-1]<<1);
					if (dp[x+1] > t) dp[x+1] = t;
				}
			}
		}
		s += dp[W];
	}
	ans = H*((W>>1)+1) + s;
	if (s > K) s = K;
	ans -= s<<1, K -= s;
	if (ans > K) ans -= K; else ans = 0;
	printf("%d\n", ans);
	return 0;
}
