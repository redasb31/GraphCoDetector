#include<stdio.h>
#define min(a,b)(a<b?a:b)
int H,W,M[60][60],i,j;
int main()
{
	scanf("%d%d",&H,&W);
	for(i=0;i<=H;i++)M[i][0]=100000;
	for(i=0;i<=W;i++)M[0][i]=100000;
	M[0][1]=0;
	for(i=1;i<=H;i++)
		for(j=1;j<=W;j++)
		{
			scanf("%1d",&M[i][j]);
			M[i][j]+=min(M[i-1][j],M[i][j-1]);
		}
	printf("%d\n",M[H][W]);
	return 0;
}