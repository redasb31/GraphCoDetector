#include<stdio.h>
#include<stdlib.h>
#define TYPE int
#define INF 9223372036854775807

int main() {
	int N, K;
	long long ans = INF, tmp = -1;
	scanf("%d%d", &N, &K);
	int *X = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &X[i]);
	}

	for (int i = 0; i <= N - K; i++)//先頭から長さK全探索
	{
		tmp = (long long)X[i + K - 1] - X[i];
		if (abs(X[i + K - 1]) <= abs(X[i]))
		{
			tmp += (long long)abs(X[i + K - 1]);
		}
		else
		{
			tmp += (long long)abs(X[i]);
		}
		if (tmp < ans)
		{
			ans = tmp;
		}
	}
	printf("%lld\n", ans);

	return 0;
}