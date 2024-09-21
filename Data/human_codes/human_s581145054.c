#include<stdio.h>
int main()
{
  int N;
  scanf("%d",&N);
  int A[N];
  int i;
  double ave=0;
  for(i=0;i<N;i++){
  	scanf("%d",&A[i]);
    ave=ave+A[i];
  }
  ave=ave/N;
  int P;
  for(i=1;i<100;i++){
    if((i-0.5<ave)&&(i+0.5>=ave)){
      P=i;
      break;
    }
  }
  int sum=0;
  for(i=0;i<N;i++){
    sum=(A[i]-P)*(A[i]-P);
  }
  printf("%d",sum);
  return 0;
}
    