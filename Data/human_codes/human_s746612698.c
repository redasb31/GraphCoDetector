#include <stdio.h>
#include <stdlib.h>

#define int long long

int main(){
	int K, i, N = 50;
	scanf("%lld", &K);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		a[i] = N - 1 + K / N;
	}
	for(i = 0; i < K % N; i++){
		a[i] += N - K % N + 1;
	}
	for(i = K % N; i < N; i++){
		a[i] -= K % N;
	}
	for(i = 0; i < N; i++){
		printf("%lld ", a[i]);
	}
	return 0;
}