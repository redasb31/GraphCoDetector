#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){

  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  if((a==1&&b==2)||(a==2&&b==1)) printf("3");
  else if((a==1&&b==3)||(a==3&&b==1)) printf("2");
  else if((a==3&&b==2)||(a==2&&b==3)) printf("1");
}