#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i;
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int) * n);
	int *b = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(i = 0; i < n; i++){
		if(i % 2 == 0){
			b[i / 2] = a[n - i - 1];
		}
		else{
			b[n - i / 2 - 1] = a[n - i - 1];
		}
	}
	for(i = 0; i < n; i++){
		printf("%d ", b[i]);
	}
	return 0;
}