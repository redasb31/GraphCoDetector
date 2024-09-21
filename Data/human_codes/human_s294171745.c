#include <stdio.h>

#define Mod 998244353

long long div_mod(long long x, long long y, long long z)
{
	if (x % y == 0) return x / y;
	else return (div_mod((1 + x / y) * y - x, (z % y), y) * z + x) / y;
}

long long combination(int n, int k)
{
	if (k == 0) return 1;
	
	static long long ans[300][300] = {};
	if (ans[n][k] != 0) return ans[n][k];
	
	int i;
	long long x, y;
	for (i = n, x = 1; i >= n - k + 1; i--) x = x * i % Mod;
	for (i = 2, y = 1; i <= k; i++) y = y * i % Mod;
	ans[n][k] = div_mod(x, y, Mod);
	return ans[n][k];
}

int main()
{
	int K;
	char S[301];
	scanf("%s %d", S, &K);

	int i, j, k, l, m, count[151][2] = {}, sum[2] = {};
	count[0][S[0] - '0']++;
	for (l = 1, k = 0; S[l] != 0; l++) {
		if (S[l] == S[l-1] || S[l] == '1') count[k][S[l] - '0']++;
		else count[++k][0]++;			
	}
	
	long long dp[151][301][301] = {};
	if (count[0][0] == 0) i = 1;
	else i = 0;
	dp[i][0][count[i][0]+1] = 1;
	for (j = 1; j <= count[i][1]; j++) {
		for (k = 1; k <= count[i][0]; k++) dp[i][j][k] = combination(j + count[i][0] - k - 1, j - 1);
	}
	
	for (sum[0] = count[i][0], sum[1] = count[i++][1]; count[i][1] > 0; i++) {
		for (l = 0; l <= sum[1]; l++) {
			for (k = 1; k <= sum[0] + 1; k++) dp[i][l][k+count[i][0]] = dp[i-1][l][k];
		}
		sum[0] += count[i][0];
		for (j = 1; j <= count[i][1]; j++) {
			for (l = 0; l <= sum[1]; l++) {
				for (k = 1; k <= sum[0]; k++) {
					for (m = sum[0] - count[i][0] + 1; m >= k - count[i][0] + 1 && m >= 1; m--) dp[i][l+j][k] = (dp[i][l+j][k] + dp[i-1][l][m] * combination(j + m + count[i][0] - k - 2, j - 1)) % Mod;
				}
			}
		}
		sum[1] += count[i][1];
	}
	
	long long ans = 0;
	for (j = 0; j <= K && j <= sum[1]; j++) {
		for (k = 1; k <= sum[0] + 1; k++) ans = (ans + dp[i-1][j][k]) % Mod;
	}
	printf("%lld\n", ans);
	fflush(stdout);
	return 0;
}