#include<stdio.h>
int main( ){
  double a,b,c;
  scanf("%lf %lf",&a,&b);
  c = 1/a+1/b;
  c = 1/c;
  printf("%.10f",c);
  return 0;
}
