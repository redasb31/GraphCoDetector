#include <stdio>

int dp[21][(1 << 21)];
int can[21][21];

int main()
{
	int n; cin >> n;

	for (auto i = 0; i < n; i++)
		for (auto j = 0; j < n; j++)
			scanf("%d", &can[i][j]);

	for (auto i = 0; i < n; i++)
		dp[0][1 << i] = can[0][i];

	for (auto i = 1; i < n; i++)
		for (auto mask = 1; mask < (1 << n); mask++)
			for (auto j = 0; j < n; j++)
				if (can[i][j] && (mask & (1 << j))) {
					dp[i][mask] += dp[i - 1][mask ^ (1 << j)];
					dp[i][mask] %= (int)(1e9 + 7);
				}

	cout << dp[n - 1][(1 << n) - 1] << endl;
	
}
