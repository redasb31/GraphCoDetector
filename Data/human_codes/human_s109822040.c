#include<stdio.h>

int main(){
  long long n,a[10001],i,b[10001];
  scanf("%lld",&n);
  for(i=1;i<=n;i++){
    scanf("%lld",&a[i]);
    b[a[i]]=i;
  }
  for(i=1;i<=n;i++){
    printf("%lld ",b[i]);
  }
  return 0;
}
