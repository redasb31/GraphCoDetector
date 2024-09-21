#include <stdio.h>
#include <string.h>


int main(void) {
	long long int n, i = 2;
	
	scanf("%lld", &n);
	printf("%lld:", n);
	while(i*i <= n){
		if(n % i == 0){
			n /= i;
			printf(" %lld", i);
		}
		else i++;
	}
	if(n != 1) printf(" %lld", n);
	printf("\n");
	return 0;
}