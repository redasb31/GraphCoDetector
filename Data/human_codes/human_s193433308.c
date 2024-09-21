#include <stdio.h>

int main(){
  long n=0,m=1;
  scanf("%d",&n);
  while(n!=0){
    n=n>>1;
    m=m<<1;
  }
  printf("%d",m);
  return 0;
}
