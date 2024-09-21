/*
  AOJ 2213
  Title:The Number of Solutions for a Polynomial
  @kankichi573
*/
#include <stdio.h>
int N,P,a[101];
int calc_poly_mod(int a[],int x,int n,int p)
{
  int i,sum;
  unsigned long long w;
  for(i=0,sum=0;i<=n;i++)
    {
      w = sum*x;
      sum = w%p;
      sum = (sum+a[n-i])%p;
    }
  return(sum);
}
main()
{
  int i,cnt;

  while(scanf("%d %d",&N,&P) && (N||P))
    {
      for(i=0;i<=N;i++)
	scanf("%d",&a[i]);
      for(i=0,cnt=0;i<P;i++)
	if(0==calc_poly_mod(a,i,N,P))
	  cnt++;
      printf("%d\n",cnt);
    }
  return(0);
}