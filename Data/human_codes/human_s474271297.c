#include <stdio.h>

int N;
int W;
long long dp[110][100100];
long long w[110];
long long v[110];

long long max(long long a, long long b)
{
	if (a > b)
		return a;
	return b;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &W);
	for (long long i = 0; i < N; i++)
		scanf("%lld%lld", w+i, v+i);

	for (long long i = 0; i < N; i++)
	{
		for (long long j = 0; j <= W; j++)
		{
			if (j - w[i] >= 0){
				dp[i+1][j] = max(dp[i][j - w[i]] + v[i], dp[i+1][j]);
			}

			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
		}
	}
	printf("%lld", dp[N][W]);
	return 0;
}