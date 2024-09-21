#include <stdio.h>

#define lln long long int

int main(){
	lln A, B, C, D, E;
	scanf("%lld%lld", &A, &B);
	for(C = 1; ; C <<= 1){
		if(C >= B){
			C >>= 1;
			if(C >= A){
				D = B - C;
				break;
			}
			else{
				A -= C;
				B -= C;
				C = 1;
			}
		}
	}
	for(E = 1; ; E <<= 1){
		if(E > D){
			E--;
			break;
		}
	}/*
	printf("C:%lld\n", C);
	printf("D:%lld\n", D);
	printf("E:%lld\n", E);*/
	if(E >= A){
		printf("%lld\n", 2 * C - A);
	}
	else{
		printf("%lld\n", 2 * (C - A) + E + 1);
	}
	return 0;
}