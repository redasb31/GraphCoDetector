// AOJ 2768 Scanner
// 2018.4.18 bal4u

#include <stdio.h>

// バッファを経ずstdinから数値を得る
//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

int  T[52];
char dp[52][1002][1002];

int main()
{
	int N, s, i, j, k, ans;

	N = in();
	s = 0; for (i = 0; i < N; i++) s += T[i] = in();

    dp[0][0][0] = 1;
	for (i = 0; i < N; i++) for (j = 0; j < 1000; j++) for (k = 0; k < 1000; k++) {
		if (!dp[i][j][k]) continue;
		if (j+T[i] < 1000) dp[i+1][j+T[i]][k] = 1;
        if (k+T[i] < 1000) dp[i+1][j][k+T[i]] = 1;
		dp[i+1][j][k] = 1;
    }

	ans = 0x10101010;
    for (i = 0; i < 1000; i++) for (j = 0; j < 1000; j++) {
		if (dp[N][i][j]) {
			k = i; if (k < j) k = j;
			if (k < s-i-j) k = s-i-j;
			if (k < ans) ans = k;
		}
	}
	printf("%d\n", ans);
	return 0;
}
