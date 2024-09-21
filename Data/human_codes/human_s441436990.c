#include<stdio.h>

void main(){
  int n,ans;
  scanf("%d",&n);
  if(n%2==0){
    ans=n/2;
  }else{
   ans=(n+1)/2;
  }
  printf("%d\n",ans);
  return 0;
} 