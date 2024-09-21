#include <stdio.h>
#include <math.h>

int prime(long x){
	long i;
	int flag=1; //素数なら1，違うなら0
	
	for(i=3; i<=sqrt(x); i+=2) {
		if(x%i==0) {
			flag=0;
			break;
		}
	}
	
	return flag;
}

int main(void){
	while(1){
		long n, i, count=0;
		
		
		scanf(" %ld", &n);
		if(n==0) break;
	
		for(i=3; i<=n/2; i+=2){
			if(prime(i)==1 && prime(n-i)==1) {
				count++;
				//printf("%ld + %ld\n", i, n-i);	
			}
		}
	
		printf("%ld\n", count);
	}

	return 0;
}