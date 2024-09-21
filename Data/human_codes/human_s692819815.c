/*
  AOJ 2551
  Title:N and K
  @kankichi573
*/
#include <stdio.h>

long long N,K;
int C;

main()
{
  int i,ret;
  
  scanf("%d",&C);
  for(i=0;i<C;i++)
    {
      scanf("%lld %lld",&N,&K);
    
      if(K>((N%2)?N+1:N)/2)
	ret=-1;
      else
	{
	  N -= (N%3);
	  if(K<=N/3+1)
	    ret=N/3+K;
	  else
	    ret=1+2*N/3+(K-(N/3+1))*2;
	}
      printf("%d\n",ret);
    }
  return(0);
}