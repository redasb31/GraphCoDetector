#include<stdio.h>
#include<stdlib.h>
int a(const void * a, const void * b)
{
	return(*(int*)a - *(int*)b);
}
main()
{
	int n, i, br=0;
	scanf("%d", &n);
	int A[n], F[n];
	for(i=0;i<n;i++)
	{
		scanf("%d", &A[i]);
	F[i]=A[i];
	}
	qsort(A, n, sizeof(int), a);
	for(i=0;i<n;i++)
	{
		if(A[i]!=F[i] )//&& //A[i+1]!=F[i])
		br=br+1;
	}
	printf("%d", br);
	return 0;
}