#include <stdio.h>
#include <string.h>

#define N	5000
#define MD	1000000007

long long power(int a, int k) {
	long long b = a, p = 1;

	while (k) {
		if (k & 1)
			p = p * b % MD;
		b = b * b % MD;
		k >>= 1;
	}
	return p;
}

int main() {
	static char cc[N + 1];
	static int dp[N + 1], dq[N + 1];
	int n, m, i, j;

	scanf("%d%s", &n, cc), m = strlen(cc);
	dp[0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= i; j++)
			dq[j] = (j == 0 ? dp[0] + dp[1] : dp[j - 1] * 2LL + (j + 1 < i ? dp[j + 1] : 0)) % MD;
		for (j = 0; j <= i; j++)
			dp[j] = dq[j];
	}
	printf("%lld\n", dp[m] * power((MD + 1) / 2, m) % MD);
	return 0;
}
