#include<stdio.h>
int main( ){
  int a,b;
  scanf("%d %d",&a,&b);
  if( a*b>0 ){
    if( a==1 ){
      printf("no");
    }
    else if( b==1 ){
      printf("no");
    }
    else if( a*b%2==0 ){
      printf("yes");
    }else{
      printf("no");
    }
  }
  return 0;
}