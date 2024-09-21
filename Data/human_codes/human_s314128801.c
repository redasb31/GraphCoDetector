/*
  AOJ 2145
  Title:Sashimi
  @kankichi573
*/
#include <stdio.h>
#include <limits.h>
#include <string.h>
#define min(x,y) (((x)<(y))?(x):(y))
long long weight[100],memo[100][100];

long long solve(long long w[],int n) 
{
  long long min_,wall,w1,ret;
  int i;

  if((ret=memo[(w-weight)][n]))
    return(ret);

#ifdef DEBUG
  for(i=0;i<n;i++)
    printf("%lld|",w[i]);
  printf("\n");
#endif
  if(n==1)
    return(0);
  if(n==2)
    return(w[0]+w[1]);

  for(i=wall=0;i<n;i++)
    wall += w[i];
  //printf("wall=%lld\n",wall);

  min_=LLONG_MAX;
  for(i=1;i<=n-1;i++)
    {
      w1=wall+solve(w,i)+solve(w+i,n-i);
      //printf("w1=%lld\n",w1);
      min_=min(min_,w1);
    }
  memo[(w-weight)][n]=min_;
  return(min_);
}


main()
{
  int n,i;
  long long ret;

  scanf("%d ",&n);
  for(i=0;i<n;i++)
    scanf("%lld",&weight[i]);

  ret=solve(weight,n);
  printf("%lld\n",ret);
}