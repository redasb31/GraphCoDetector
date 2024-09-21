#include <stdio.h>

typedef long long ll;

#define MOD 1000000007
#define MAX_N 200

ll dp[MAX_N][MAX_N+1] = {0}; // dp[n][rest U] = ??´????????°

int main() {
	int N;
	char c[MAX_N];
	char buf[100];
	int sz = 0;
	ll ans = -1;
	int i, j;

	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%s", buf);
		if (buf[0] != '-') c[sz++] = buf[0];
	}
	N = sz;

	if (N == 0) {
		ans = 1;
	}
	else if (c[0] == 'D') {
		ans = 0;
	}
	else {
		dp[0][1] = 1; // c[0] : 'U'
		for (i = 0; i < N-1; ++i) {
			for (j = 0; j < N; ++j) {
				if (c[i+1] == 'U') {
					dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
					if (j >= 1) {
						dp[i+1][j] = (dp[i+1][j] + j * dp[i][j]) % MOD;
					}
				}
				else { // D
					if (j >= 1) {
						dp[i+1][j] = (dp[i+1][j] + j * dp[i][j]) % MOD;
						dp[i+1][j-1] = (dp[i+1][j-1] + j * j * dp[i][j]) % MOD;
					}
				}
			}
		}
		ans = dp[N-1][0];
	}	

	printf("%lld\n", ans);

	return 0;
}