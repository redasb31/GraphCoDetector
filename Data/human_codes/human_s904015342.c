#include<stdio.h>

int main(){
  double s,i,w;
  scanf("%lf %lf",&s,&w);
  w = w * 2.0;

  if( w < s ){
    printf("safe\n");
  }else if( w >= s){
    printf("unsafe\n");
  }

}