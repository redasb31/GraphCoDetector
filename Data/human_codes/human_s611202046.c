#include <stdio.h>

int main(){
  int N;
  scanf("%d",&N);
  if(N%2==0){
   printf("%d\n",N/2);
  }else{
    printf("%d\n",N/2+1);
  }
  return 0;
}