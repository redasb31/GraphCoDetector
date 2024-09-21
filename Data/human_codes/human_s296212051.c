#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, a, b, i, now = 0;
	int M = 86400, K = 10800;
	scanf("%d", &N);
	int *D = (int *)malloc(sizeof(int) * 2 * M);
	for(i = 0; i < 2 * M; i++){
		D[i] = 0;
	}
	for(i = 0; i < N; i++){
		scanf("%d%d", &a, &b);
		D[(now + a) % M]++;
		D[(now + a) % M + M]++;
		now = (now + a + b) % M;
	}
	for(i = 0, now = 0; i <= K; i++){
		now += D[i];
	}
	int ans = now;
	for(i = 0; i < M; i++){
		now -= D[i];
		now += D[i + K + 1];
		ans = max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}