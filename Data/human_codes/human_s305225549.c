#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD(a * a), N / 2);
	}
	else{
		return MOD(a * power(a, N - 1));
	}
}

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int N, K, L, i, j, k, ans, j_max, next_j_max;
	scanf("%lld%lld", &N, &K);
/*	for(i = 1, L = 1; i <= K; i++){
		L += (K + i - 1) / i;
	}
	printf("L = %lld\n", L);
*/	L = K * K;
	int **dp = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 0; i <= N; i++){
		dp[i] = (int *)malloc(sizeof(int) * (L + 1));
		for(j = 0; j <= L; j++){
			dp[i][j] = 0;
		}
	}
	if(N == K){
		dp[N][0] = K;
		dp[N][1] = 1;
		next_j_max = 1;
	}
	else{
		dp[N][0] = K + 1;
		next_j_max = 0;
	}
	for(i = N; i > 1; i--){
		j_max = next_j_max;
//		printf("(i, j_max) = (%lld, %lld)\n", i, j_max);
		for(j = 0; j <= j_max; j++){
			for(k = 0; k <= K; k++){
				if(k + j < i - 1 || i - 1 < k){
					dp[i - 1][j] = MOD(dp[i - 1][j] + dp[i][j]);
				}
				else{
					dp[i - 1][j + (k + j) / (i - 1)] = MOD(dp[i - 1][j + (k + j) / (i - 1)] + dp[i][j]);
					next_j_max = max(next_j_max, j + (k + j) / (i - 1));
				}
			}
		}
	}
/*	for(i = 1; i <= N; i++){
		printf("i = %lld\n", i);
		for(j = 0; j <= L; j++){
			printf("%lld  ", dp[i][j]);
		}printf("\n");
	}
*/	ans = MOD(((K * (K + 1)) / 2) * power(K + 1, N - 1) * N);
	for(j = 0; j <= next_j_max; j++){
		ans = MOD(ans - dp[1][j] * j);
	}
	printf("%lld\n", ans);
	return 0;
}