#include<stdio.h>
int N,A[105][105]={0},i,j,k,l,R,t;
int main()
{
	scanf("%d",&N);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%d",&A[i][j]);
	for(i=0;i<N;i++)
		for(j=N-2;j>=0;j--)
			A[i][j]+=A[i][j+1];
	for(i=R=0;i<N;i++)
		for(j=0;j<N;j++)
			for(k=j;k<=N;k++)
				for(l=i,t=0;l<N;l++)
				{
					t+=A[l][j]-A[l][k];
					R=R>t?R:t;
				}
	printf("%d\n",R);
	return 0;
}