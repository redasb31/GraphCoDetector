#include<stdio.h>
#include<math.h>

int main(void)
{
  int a,b,i,keta,sum[200];

  for(i=0;i<200;i++){
    scanf("%d %d",&a,&b);
    sum[i]=a+b;
  }

  for(i=0;i<200;i++){
    while(sum[i]>0){
      keta=0;
      sum[i]/=10;
      keta+=1;
    }
    printf("%d\n",keta);
  }

  return 0;
}