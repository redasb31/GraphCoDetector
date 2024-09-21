#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, Q, i, tmp;
	scanf("%d%d", &N, &Q);
	int *A = (int *)malloc(sizeof(int) * Q);
	int *B = (int *)malloc(sizeof(int) * Q);
	for(i = 0; i < Q; i++){
		scanf("%d%d", &A[i], &B[i]);
		A[i]--;
		B[i]--;
	}
	int *ball = (int *)malloc(sizeof(int) * (Q + 1));
	ball[0] = 0;
	for(i = 0; i < Q; i++){
		if(A[i] == ball[i]){
			ball[i + 1] = B[i];
		}
		else if(B[i] == ball[i]){
			ball[i + 1] = A[i];
		}
		else{
			ball[i + 1] = ball[i];
		}
	}
/*	for(i = 0; i <= Q; i++){
		printf("ball[%d] = %d\n", i, ball[i]);
	}
*/	int *P = (int *)malloc(sizeof(int) * N);
	int *can = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		P[i] = i;
		can[i] = 0;
	}
	can[ball[Q]] = 1;
	for(i = Q; i >= 0; i--){
		can[P[max(0, ball[i] - 1)]] = 1;
		can[P[min(N - 1, ball[i] + 1)]] = 1;
		if(i == 0){
			break;
		}
		else{
			tmp = P[A[i - 1]];
			P[A[i - 1]] = P[B[i - 1]];
			P[B[i - 1]] = tmp;
		}
	}
	int ans = 0;
	for(i = 0; i < N; i++){
		ans += can[i];
	}
	printf("%d\n", ans);
	return 0;
}