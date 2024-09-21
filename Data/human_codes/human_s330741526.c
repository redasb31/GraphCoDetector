
#define MOD 1000000007
long long n, m, i, j, k, dp[305][305][305];

main () {
	scanf("%llu%llu", &n, &m);
	dp[0][1][0] = 1;
	for (i = 0; i < m; i++) {
		for (j = 1; j <= n; j++) {
			for (k = 0; k <= n - j; k++) {
				dp[i + 1][j + k][0] += dp[i][j][k] * j % MOD;
				dp[i + 1][j + k][0] %= MOD;
				dp[i + 1][j][k] += dp[i][j][k] * k % MOD;
				dp[i + 1][j][k] %= MOD;
				dp[i + 1][j][k + 1] += dp[i][j][k] * (n - j - k) % MOD;
				dp[i + 1][j][k + 1] %= MOD;
			}
		}
	}

	printf("%lld\n", dp[m][n][0]);
}
