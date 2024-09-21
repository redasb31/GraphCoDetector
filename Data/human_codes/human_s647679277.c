#include <stdio.h>
#include <stdlib.h>

int N, *p, ans[100000], l = 0;

void swaps(int k){
	int i, tmp;
	for(i = k; i < N; i++){
		tmp = p[i];
		p[i] = p[i - k];
		p[i - k] = tmp;
	}
	ans[l] = k;
	l++;
}

void out(){
	int i;
	printf("p:");
	for(i = 0; i < N; i++){
		printf("%d ", p[i]);
	}
	printf("\n");
}

int main(){
	int i;
	scanf("%d", &N);
	p = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &p[i]);
//		p[i] = (N / 2 - i + N) % N;
	}
	for(i = N - 2; i >= 0; i--){
//		printf("i = %d\n", i);
		while(p[0] != i){
			swaps(1);
//			out();
		}
		while(p[1] != i + 1){
			swaps(1);
			swaps(N - 1);
//			out();
		}
	}
//	out();
	printf("%d\n", l);
	for(i = 0; i < l; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}