#include <stdio.h>

int digitSum(int n){
	int sum = 0;
	while (n >= 1){
		sum += (n % 10);
		n/=10;
	}
	return sum;
}

void main(){
	int K,k, i = 1;
	int cnt = 1;
	do{
		printf("K>>"); scanf("%d", &k);
	} while (k < 2 || k>100000);
	K = k;
	int min = digitSum(K);
	while (i < k*k){
		K = k*i;
		if (digitSum(K) < min) {
			min = digitSum(K); cnt=i;
		}
		i++;
	}
	printf("Output:%d when %d * %d = %d\n", min,k,cnt,k*cnt);
}