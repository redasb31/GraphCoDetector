#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int64 sum=0;
  for(i=0;i<n;i++) sum+=a[i];
  if(sum%((int64)n*(n+1)/2)!=0){
    printf("NO\n");
    return;
  }
  int64 diff=a[0]-a[n-1];
  for(i=0;i+1<n;i++) diff+=a[i+1]-a[i];
  printf("%s\n",diff==0?"YES":"NO");
  return;
}

int main(void){
  run();
  return 0;
}
