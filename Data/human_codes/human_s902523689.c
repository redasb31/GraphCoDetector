#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

int max(int a, int b){
	return a >= b ? a : b;
}

int min(int a, int b){
	return a <= b ? a : b;
}

int sum(int l, int r, int *s){
	if(r < l || r < 0){
		return 0;
	}
	if(l <= 0){
		return s[r];
	}
	else{
		return MOD(s[r] - s[l - 1]);
	}
}

signed main(){
	int N, M, i, j;
	scanf("%lld%lld", &N, &M);
	char *T = (char *)malloc(sizeof(char) * (M + 1));
	scanf("%s", T);
	int *A = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		if(T[i] == 'R'){
			A[i] = 0;
		}
		else{
			A[i] = 1;
		}
	}
	if(A[0] == 1){
		for(i = 0; i < M; i++){
			A[i] ^= 1;
		}
	}
	int *val = (int *)malloc(sizeof(int) * M);
	int *num = (int *)malloc(sizeof(int) * M);
	val[0] = A[0];
	num[0] = 1;
	for(i = 1, j = 0; i < M; i++){
		if(A[i] == A[i - 1]){
			num[j]++;
		}
		else{
			j++;
			val[j] = A[i];
			num[j] = 1;
		}
	}
	int K = j + 1;
	if(K == 1){
		int *dp1 = (int *)malloc(sizeof(int) * N);
		dp1[0] = 1;
		int *S1 = (int *)malloc(sizeof(int) * N);
		S1[0] = 1;
		for(i = 1; i < N; i++){
			dp1[i] = sum(0, i - 2, S1);
			S1[i] = MOD(S1[i - 1] + dp1[i]);
		}
		int ans = 1;
		for(i = 1; i < N; i++){
			ans = MOD(ans + (i + 1) * dp1[N - i - 1]);
		}
		printf("%lld\n", ans);
		return 0;
	}
	if(N % 2 == 1){
		i = 0;
		printf("%d\n", j / i);
		return 0;
	}
	int Ooddmin = 2 * (num[0] / 2) + 1;
	for(i = 0; i < K; i++){
		if(num[i] % 2 == 0 || val[i] == 1){
			continue;
		}
		Ooddmin = min(Ooddmin, num[i]);
	}
	int *dp = (int *)malloc(sizeof(int) * N);
	dp[0] = 1;
	int **S = (int **)malloc(sizeof(int *) * 2);
	S[0] = (int *)malloc(sizeof(int) * N);
	S[0][0] = 1;
	S[1] = (int *)malloc(sizeof(int) * N);
	S[1][0] = 0;
	for(i = 1; i < N; i++){
		dp[i] = sum(i - Ooddmin - 1, i - 2, S[i % 2]);
		S[i % 2][i] = MOD(S[i % 2][i - 1] + dp[i]);
		S[1 - i % 2][i] = S[1 - i % 2][i - 1];
	}
/*	for(i = 0; i < N; i++){
		printf("dp[%lld] = %lld\n", i, dp[i]);
	}
*/	int ans = 0;
	for(i = 1; i <= Ooddmin; i += 2){
		ans = MOD(ans + (i + 1) * dp[N - i - 1]);
	}
	printf("%lld\n", ans);
	return 0;
}