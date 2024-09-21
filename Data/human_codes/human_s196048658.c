#include <stdio.h>

#define MAX_PRIME	(1300000)
#define IS_PRIME(n)	(prime[n]==1?0:1)

int prime[MAX_PRIME + 1];



void make_prime(void)
{
    int i;
    int j;
    int n;
    int c;
    
    for (i = 2; i * i <= MAX_PRIME; i++){
        if (prime[i] == 0){
            for (j = i * 2; j <= MAX_PRIME; j += i){
				prime[j] = 1;
            }
        }
    }
}

int main(void)
{
	int n;
	int i;
	int gap;
	
	make_prime();
	
	while (1){
		scanf("%d", &n);
		if (n == 0){
			break;
		}
		
		gap = 0;
		for (i = n; prime[i] == 1; i++){
//printf("<%d>", i);
			gap++;
		}
		
		for (i = n; !IS_PRIME(i); i--){
//printf("[%d]", i);
			gap++;
		}
		printf("%d\n", gap);
	}
	
	return (0);
}