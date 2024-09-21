#include <stdio.h>
#include <stdlib.h>


#define	ll_int	long long int


int Binary_Search(ll_int *box, int n, ll_int num)
{
	int mid;
	int left, right;


	left = 0;
	right = n - 1;
	while(left <= right){
		mid = (left + right) / 2;

		if(num == box[mid])
			return 1;
		else if(num < box[mid])
			right = mid - 1;
		else if(box[mid] < num)
			left = mid + 1;
	}

	return 0;
}


int main()
{
	int n, m;
	ll_int *A, *B;
	int i, j;


	scanf("%d", &n);

	A = (ll_int *)malloc(sizeof(ll_int) * n);

	for(i = 0; i < n; i++)
		scanf("%lld", &A[i]);


	scanf("%d", &m);

	B = (ll_int *)malloc(sizeof(ll_int) *m);

	for(i = 0; i < m; i++)
		scanf("%lld", &B[i]);


	for(i = 0; i < m; i++)
		if(Binary_Search(A, n, B[i]) != 1)
			break;

	if(i == m)
		printf("1\n");
	else
		printf("0\n");

	return 0;
}
