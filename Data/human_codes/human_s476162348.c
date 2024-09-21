/*
AizuOnline A1501
Title　Grid
*/
#include <stdio.h>
#define min(x,y) (((x)<(y))?(x):(y))
int number[2000];
int primes[]={2,3,5,7,11,13,17,19,23,29,31};
//
long long combi(int n,int r)
{
  int i,j,k,q;
  long long product;
  
  for(i=n;i>n-r;i--)
    number[i]=i;
  
  for(i=r;i>=2;i--)
    {
      q=i;
      for(k=0;k<sizeof(primes)/sizeof(int);k++)
	{
	  if((q % primes[k])==0)
	    {
	      for(j=n;j>n-r;j--)
		{
		  if((number[j] % primes[k])==0)
		    {
		      number[j]/=primes[k];
		      goto NEXT;
		    }
		}
	    NEXT:
	      q /= primes[k];
	    }
	}
      if(q>1)
	for(j=n;j>n-r;j--)
	  {
	    if((number[j] % q)==0)
	      {
		number[j]/=q;
		break;
	      }
	  }
    }  
  
  product=1LL;
  
  for(i=n;i>n-r;i--)
    {
    product *= number[i];
    //printf("%d:",number[i]);
    product = product % 100000007;
    }
    
  return(product);
}
main()
{
  int r,c,a1,a2,b1,b2,x,y,x1,y1,x2,y2,k;


  while(EOF!=scanf("%d %d %d %d %d %d",&r,&c,&a1,&a2,&b1,&b2))
    {
      x=abs(a1-b1);
      y=abs(a2-b2);
      x1=r-x;        // wrap around
      y1=c-y;        // "    "
      k=((x==x1)?2:1)*((y==y1)?2:1);
      x2=min(x,x1);
      y2=min(y,y1);
      //printf("%d %d %d\n",x2,y2,k);
      printf("%lld\n",(combi(x2+y2,x2)*k)%100000007);
    }
return(0);
}