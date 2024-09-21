#include<stdio.h>

int main()
{
  int A, B, C, D, E;
  int sum = 0;

  scanf("%d%d%d%d%d",&A,&B,&C,&D,&E);

  if( A < 0){
    sum = D - (A*C) + (B*E);
  }

  else{
    sum = (B-A)*E;
  }

  printf("%d\n",sum);
  return 0;
}

