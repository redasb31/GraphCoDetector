// AOJ 1306 Balloon Collecting
// 2018.1.31 bal4u

#include <stdio.h>
#include <string.h>

#define INF 0x30303030
#define ABS(a)  ((a)>=0?(a):-(a))

int p[41], t[41];
int dp[41][4];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int main()
{
	int n, i, j, d, x, id, ans;
	
	while(n = in()){
		for (i = 1; i <= n; i++) p[i] = in(), t[i] = in();
		if (p[1] > t[1]) { puts("NG 1"); continue; }

		memset(dp, INF, sizeof(dp));
		dp[0][0] = 0, id = 1;
		for (i = 0; i < n; i++) for (j = 0; j < 4; j++) if (dp[i][j] < INF) {
			id = i;
			d = ABS(p[i+1]-p[i]);
			if (j < 3 && d*(j+1) <= t[i+1]-t[i]) {
				x = dp[i][j] + d;
				if (dp[i+1][j+1] > x) dp[i+1][j+1] = x;
			}
			if (p[i]*(j+1)+p[i+1] <= t[i+1]-t[i]) {
				x = dp[i][j] + p[i] + p[i+1];
				if (dp[i+1][1] > x) dp[i+1][1] = x;
			}
		}

		ans = INF;
		for (j = 0; j < 4; j++) if (dp[n][j] < ans) ans = dp[n][j];
		if (ans < INF) printf("OK %d\n", ans + p[n]);
		else printf("NG %d\n", id+1);
	}
	return 0;
}
