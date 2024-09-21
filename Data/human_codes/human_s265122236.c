// AOJ 2326: Number Sorting
// 2017.11.27 bal4u@uu

#include <stdio.h>
#include <string.h>

long long dp[100002];
long long a, b, p;

long long tbl[12] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 
100000000LL, 1000000000LL, 10000000000LL, 100000000000LL };

long long bsch(long long x)
{
	int m, l = 0, r = 12;

    while (l < r) {
        m = (l + r) >> 1;
		if (tbl[m] == x) return x;
        if (tbl[m] < x) l = m + 1; else r = m;
    }
	return tbl[l-1];
}

void calc(long long n)
{
    long long k, v = dp[n-a], m = n;

	while (m < b) {
		if (m == n) { dp[m-a+1] += v; if (dp[m-a+1] >= p) dp[m-a+1] -= p; }
		else        { dp[m-a  ] += v; if (dp[m-a]   >= p) dp[m-a  ] -= p; }
        m *= 10;
		k = bsch(m); if (k > b) k = b;
		k -= a, dp[k] -= v; if (dp[k] < 0) dp[k] += p;
    }
}

int main()
{
	long long i, ii, ans;

	while (scanf("%lld%lld%lld", &a, &b, &p) && p > 0) {
		memset(dp, 0, sizeof(dp));
	    b++;
		dp[0] = 1, calc(a);
		ans = dp[0]; if (ans >= p) ans -= p;
		for (ii = 1, i = a+1; i < b; i++, ii++) {
			dp[ii] += dp[ii-1]; if (dp[ii] >= p) dp[ii] -= p;
			calc(i);
	        ans += dp[ii]; if (ans >= p) ans -= p;
		}
		printf("%lld\n", ans);
	}
	return 0;
}