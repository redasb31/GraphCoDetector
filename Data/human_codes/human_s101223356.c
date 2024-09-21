#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{
	long long int N,K,answer=1;
	int i;
	
	scanf("%lld",&N);
	scanf("%lld",&K);

	
	if(K==1) exit(0);
	
	
	if(N < K){
		for(i=0; i < N; i++){
			answer *= (K-i);
		}
	}else{
		answer = (K * pow(K-1,N-1));
	}
	
	printf("%lld",answer);
	
	return 0;
}