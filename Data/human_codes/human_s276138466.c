#include <stdio.h>
#include <stdlib.h>
#define datatype int

//比較関数
int compare(datatype a, datatype b){
	return a - b;
}

//昇順
void sort_sub(datatype *origin, int left, int right, datatype *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if(k == right){
				origin[i] = tmp[j];
				j++;
			}
			else if(compare(tmp[j], tmp[k]) <= 0 && j < half){
				origin[i] = tmp[j];
				j++;
			}
			else{
				origin[i] = tmp[k];
				k++;
			}
		}
	}
}

void sort(datatype *origin, int N){
	datatype *tmp = (datatype *)malloc(sizeof(datatype) * N);
	sort_sub(origin, 0, N, tmp);
	free(tmp);
}

int main(){
	int N, M, i, j;
	scanf("%d", &N);
	int *D = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &D[i]);
	}
	scanf("%d", &M);
	int *T = (int *)malloc(sizeof(int) * M);
	for(j = 0; j < M; j++){
		scanf("%d", &T[j]);
	}
	sort(D, N);
	sort(T, M);
	for(i = 0, j = 0; j < M && i < N;){
		if(D[i] == T[j]){
			i++;
			j++;
		}
		else if(D[i] > T[j]){
			printf("NO\n");
			return 0;
		}
		else{
			i++;
		}
	}
	if(j < M){
		printf("NO\n");
	}
	else{
		printf("YES\n");
	}
	return 0;
}