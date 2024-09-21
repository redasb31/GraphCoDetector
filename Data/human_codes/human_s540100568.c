#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a > b ? a : b;
}

int cmp1(const void *a, const void *b){
	return (*(int*)a) - (*(int*)b);
}

int cmp2(const void *a, const void *b){
	return -(*(*((int**)a) + 1)) + *(*((int**)b) + 1);
}

int main(void){
	int n, m;
	long sum = 0;
	scanf("%d %d", &n, &m);
	int *card = malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++)scanf("%d", card + i);
	int **swap = malloc(sizeof(int*) * m);
	for(int i = 0; i < m; i++){
		swap[i] = malloc(sizeof(int) * 2);
		scanf("%d %d", swap[i], swap[i] + 1);
	}
	qsort(card, n, sizeof(int), cmp1);
	qsort(swap, m, sizeof(int*), cmp2);
	int p = 0;
	for(int i = 0; i < n; i++){
		sum += max(card[i], swap[p][1]);
		if(swap[p][0])swap[p][0]--;
		if(swap[p][0] == 0 && p < m - 1)p++;
		if(swap[p][0] == 0 && p == m - 1)swap[p][1] = 0;
	}
	//for(int i = 0; i < n; i++)printf("%d\n", card[i]);
	//for(int i = 0; i < m; i++)printf("%d %d\n", swap[i][0], swap[i][1]);
	printf("%ld\n", sum);
	return 0;
}
