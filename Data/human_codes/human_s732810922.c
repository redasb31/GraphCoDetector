// AOJ 0604: Take the 'IOI' train
// 2017.12.5 bal4u@uu

#include <stdio.h>
#include <string.h>

char s[2002], t[2002];
int dp[2][2002][2002];

int main()
{
	int n, m, i, j, ans;
	char *p;

	fgets(s, 20, stdin);
	sscanf(s, "%d%d", &m, &n);
	fgets(s, 2002, stdin);
	fgets(t, 2002, stdin);

	for (p = s; *p > ' '; p++) *p = (*p >> 1) & 1;
	for (p = t; *p > ' '; p++) *p = (*p >> 1) & 1;

	ans = 0;
	memset(dp[0], -1, sizeof(dp[0]));

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (dp[s[i]][i+1][j] < dp[1-s[i]][i][j] + 1)
				dp[s[i]][i+1][j] = dp[1-s[i]][i][j] + 1;

			if (dp[t[j]][i][j+1] < dp[1-t[j]][i][j] + 1)
				dp[t[j]][i][j+1] = dp[1-t[j]][i][j] + 1;

			if (ans < dp[0][i][j]) ans = dp[0][i][j];
		}
		if (dp[s[i]][i+1][n] < dp[1-s[i]][i][n] + 1)
			dp[s[i]][i+1][n] = dp[1-s[i]][i][n] + 1;
		if (ans < dp[0][i][n]) ans = dp[0][i][n];
	}
	for (j = 0; j < n; j++) {
		if (dp[t[j]][m][j+1] < dp[1-t[j]][m][j] + 1)
			dp[t[j]][m][j+1] = dp[1-t[j]][m][j] + 1;
		if (ans < dp[0][m][j]) ans = dp[0][m][j];
	}
	if (ans < dp[0][m][n]) ans = dp[0][m][n];

	printf("%d\n", ans);
	return 0;
}