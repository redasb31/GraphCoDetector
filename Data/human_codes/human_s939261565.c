#include <stdio.h>
typedef struct {
	int s, v, n;
} pair;

int dp[16][1024] = {0};
int _c = 0;
pair lazy[100000];

int append(int s, int v, int n)
{
	lazy[_c++] = (pair){s, v, n};
	return (0);
}

int apply(void)
{
	int it = _c - 1;
	while (it >= 0){
		dp[lazy[it].s][lazy[it].v] += lazy[it].n;
		it--;
	}
	_c = 0;
	return (0);
}

int main(void)
{
	int i, j, k;
	int n, s;

	dp[0][0] = 1;
	for (i = 0; i <= 100; i++){
		for (j = 0; j < 9; j++){
			for (k = 0; k <= 1000; k++){
				if (dp[j][k]) append(j + 1, k + i, dp[j][k]);
			}
		}
		apply();
	}

	while (scanf("%d %d", &n, &s), n + s){
		printf("%d\n", dp[n][s]);
	}
	return (0);
}