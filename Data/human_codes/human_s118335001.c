/*
  AOJ 2527
  Title:MLE
  @kankichi573
*/
#include <stdio.h>
#include <string.h>

int division[256];
long long memo[625*625*4]; // 10^8/256*4
int x0,n,k;

long long next_rand(unsigned long long int x)
{
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  return(x);
}

int div(long long x,int nbits)
{
  int y,mask;
  mask = (1<<nbits)-1;
  y = x >> (64-nbits);
  return(y & mask);
}
int compare_ll(const void *a, const void *b)
{
  if( *(long long *)a > *(long long *)b)
    return(1);
  if( *(long long *)a < *(long long *)b)
    return(-1);
  if( *(long long *)a > *(long long *)b)
    return(0);
}
main()
{
  int i,i1,j,d,dv,mask;
  long long x;

  scanf("%d %d %d\n",&n,&k,&x0);
  memset(division,0,sizeof(division));
  memset(memo    ,0,sizeof(memo));

  if(x0==0)
    {
      printf("0\n");
      return(0);
    }

  for(i=0,x=x0;i<n;i++)
    {
      //printf("%lld:",x);
      d=div(x,8);
      division[d]++;
      x=next_rand(x);
    }
  k--;
  for(i=-128;i<127;i++)
    {
      i1=i;
      if(i1<0)
	i1+=256;
      dv=division[i1];

      if(k<dv)
	{
	  mask=i1;
	  break;
	}
      k -= dv;
    }
  //printf("div=%d k=%d\n",mask,k);
  for(i=j=0,x=x0;i<n;i++)
    {
      d=div(x,8);
      if(d==mask)
	{
	  memo[j]=x;
	  j++;
	}
      x=next_rand(x);
    }
  qsort(memo,j,sizeof(long long),compare_ll);
  printf("%lld\n",memo[k]);
  return(0);
}