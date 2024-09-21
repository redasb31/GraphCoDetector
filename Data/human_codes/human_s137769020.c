#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define P 1000000007

int comp(const void *a, const void *b){return *(int*)a-*(int*)b;}

int main(void){
	int n, i, j;
	long k;
	int a[2000];
	scanf("%d%d", &n, &k);
	for(i=0; i<n; i++){
		scanf("%d", a+i);
	}
	long A=0, b=0;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i<j && a[i]>a[j]) A++;
			if(a[i]>a[j]) b++;
		}
		A%=P; b%=P;
	}
	printf("%d %d\n", A, b);
	long ans = (A*k%P) + (k*(k-1)/2%P*b%P);
	ans%=P;
	printf("%ld\n", ans);
}
