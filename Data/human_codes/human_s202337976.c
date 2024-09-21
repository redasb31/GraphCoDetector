#include <stdio.h>
#include <stdlib.h>

int int_sort(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b){
		return -1;
	}
	else if (*(int *)a == *(int *)b){
		return 0;
	}
	return 1;
}

int main(void)
{
	int a, b, a_s, b_s;
	int team[100], N;
	int rank[100];
	int flag[100];
	int i, j, k;
	int tmp, count;
	
	for (i = 0; i < 100; i++){
		team[i] = flag[i] = 0;
	}
	
	scanf("%d", &N);
	k = N * (N - 1) / 2;
	
	for (i = 0; i < k; i++){
		scanf("%d %d %d %d", &a, &b, &a_s, &b_s);
		if (a_s == b_s){
			team[a - 1] += 1;
			team[b - 1] += 1;
		}
		else if (a_s > b_s){
			team[a - 1] += 3;
		}
		else if (a_s < b_s){
			team[b - 1] += 3;
		}
	}
	
	for (i = 0; i < N; i++){
		rank[i] = team[i];
	}
	
	qsort(team, N, sizeof(int), int_sort);
	
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (flag[i] == 0 && rank[i] == team[j]){
				rank[i] = j + 1;
				flag[i] = 1;
			}
		}
	}
	
	for (i = 0; i < N; i++){
		printf("%d\n", rank[i]);
	}
	
	return (0);
}