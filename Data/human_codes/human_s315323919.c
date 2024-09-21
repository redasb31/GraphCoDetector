#include <stdio.h>

long long power3[32];
#define LIM3 31 // 3^32 > 2^50

void prepare()
{
  int i;
  long long acc;
  for(i=0,acc=1LL;i<LIM3;i++)
    {
      power3[i]=acc;
      acc *= 3;
    }
}


int log3(long long n)
{ int i;
  for(i=0;i<LIM3;i++)
    if((n >= power3[i]) && (n < 3*power3[i]))
      return(i);
      
  return(-1);
}

int solve1(long long n)
{
  int ret;
  
  ret=log3((n+2)/2);
  
  return(ret);
}

int sum_digits(long long n)
{
  int ret;
  ret=0;
  while(n>0)
    {
      ret += (n % 3);
      n /= 3;
    }
  return(ret);
}

int solve2(long long n,long long h)
{
  int ret;
  
  ret=n/h;
  ret+=sum_digits(n % h);
  return(ret);
}


int main()
{
  long long n,n2;
  int ret,ret1,ret2;
  
  prepare();

  scanf("%lld",&n);
  ret1=solve1(n);
  
  n2 = n-(2*power3[ret1]-2);
  ret2=solve2(n2,power3[ret1]);

  ret=2*ret1+ret2;
  printf("%d\n",ret);
  
  return(0);
}

