#include <stdio.h>
#include <stdlib.h>

void digit_down(int *A, int N, int K){
	int i, j = 0;
	for(i = N - 1; ; i--){
		if(A[i] > 0){
			A[i]--;
			if(A[i] == 0){
				for(j = i; j < N; j++){
					A[j] = 0;
				}
			}
			return;
		}
		else{
			A[i] = K;
		}
	}
}

int main(){
	int N, K, i;
	scanf("%d%d", &K, &N);
	if(K % 2 == 0){
		printf("1 ");
		for(i = 1; i < N; i++){
			printf("%d ", K);
		}
	}
	else{
		int *ans = (int *)malloc(sizeof(int) * N);
		for(i = 0; i < N; i++){
			ans[i] = (K + 1) / 2;
		}
		int l = N / 2;
		for(i = 0; i < l; i++){
			digit_down(ans, N, K);
		}
		for(i = 0; i < N; i++){
			printf("%d ", ans[i]);
		}
	}
	return 0;
}