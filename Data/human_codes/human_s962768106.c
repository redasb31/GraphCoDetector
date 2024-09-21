#include<stdio.h>
int main(){
  int n,k,x,i,ans = 0;
  scanf("%d",&n);
  scanf("%d",&k);
  for (i=0;i<n;i++){
    scanf("%d",&x);
    if (x > k - x) {
      ans += k - x;
    }else {
      ans += x;
    }
  }
  ans *= 2;
  printf("%d\n",ans);
  return 0 ;
}
