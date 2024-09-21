// AOJ 2898: Prime Number
// 2019.2.19 bal4u
 
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX  10000000+2
#define SQRT 3162   // = sqrt(MAX)
char noPrime[MAX+1] = { 1, 1, 0, 0 };

void sieve()
{
	int i, j;

	for (i = 3; i <= SQRT; i+=2) {
		if (noPrime[i] == 0) {
			for (j = i*i; j < MAX; j += i) noPrime[j] = 1;
		}
	}
}

int main()
{
	int i, N, ans;

	sieve();
	scanf("%d", &N);
	ans = 0;
	if (N >= 3) ans++;
	for (i = 5; i <= N; i+=6) {
		if (noPrime[i] == 0 && noPrime[i+2] == 0) ans++;
	}
	printf("%d\n", ans << 1);
	return 0;
}
