#include <stdio.h>
#include <stdlib.h>


#define	ll_int	long long int


int main()
{
	int n, m;
	ll_int *A, *B;
	int count;
	int i, j, k;

	scanf("%d", &n);
	A = (ll_int *)malloc(sizeof(ll_int) * n);
	for(i = 0; i < n; i++)
		scanf("%lld", &A[i]);

	scanf("%d", &m);
	B = (ll_int *)malloc(sizeof(ll_int) * (m + 1));
	for(i = 0; i < m; i++)
		scanf("%lld", &B[i]);
	B[m] = 1000000001;


	// A - B の実行
	for(i = 0, j = 0; i < n; i++){
		while(j < m && B[j] < A[i])
			j++;
		if(A[i] != B[j])
			printf("%lld\n", A[i]);
	}

	return 0;
}
