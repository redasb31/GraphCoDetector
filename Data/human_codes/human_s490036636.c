#include <stdio.h>
int main(void){
  int x,y,sum=0;
  scanf("%d %d", &x, &y);
  for(int i=0;i<x;i++){
    for(int s=0;s<=100;s++){
      for(int t=0;t<=100;t++){
        sum=2*s+4*t;
        if(s+t==x&&sum==y){
          puts("Yes");
          return 0;
        }
      }
    }
  }
  puts("No");
}