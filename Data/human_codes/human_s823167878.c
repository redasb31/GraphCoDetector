#include<stdio.h>
int main(){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  printf("%d",b<=a&&c<=a?b+c:a<=b&&c<=b?a+c:a+b);
  return 0;}