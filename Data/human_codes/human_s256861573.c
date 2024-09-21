#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int64 d=n/k;
  int64 e=(k%2==0?(n+k)/k:0);
  int64 ans=d*d*d+e*e*e;
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
}
