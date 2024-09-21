#include <stdio.h>
#include <math.h>

int main(void){
	int i, j, n;
	unsigned short int s;
	int prime[500000] = {0};
	int primeList[10000] = {0};
	int primeTop = 2;
	for(i = 2; i < 500000; i++){
		if(i > sqrt(500000)) break;
		if(prime[i] == 0){
			primeTop = i;
			for(j = 1; ; j++){
				if(primeTop * j > 500000 / primeTop) break;
				prime[primeTop * j] = 1;
			}
			prime[primeTop] = 2;
		}
	}
	j = 0;
	for(i = 2; i < 500000; i++){
		if(prime[i] == 2 || prime[i] == 0){
			primeList[j] = i;
			j++;
		}
	}
	
	while(scanf("%d", &n) != EOF){
		if(n == 0) break;
		s = 0;
		for(i = 0; i < n; i++){
			s += primeList[i];
		}
		printf("%d\n", s);
	}
	
	return 0;
}