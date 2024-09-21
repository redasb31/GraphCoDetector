#include<stdio.h>

int main(){

  int n,y,b,r,t,bmax,i,j;
  double hukuri,sum,max;

  while(1){
    scanf("%d",&n);
    if(n==0)break;
    scanf("%d",&y);

    sum=1;
    max=0;

    for(i=0;i<n;i++){
      scanf("%d%d%d",&b,&r,&t);
      if(t==1)sum = sum*(1+y*(double)r/100);
      else{
	hukuri=1;
	for(j=1;j<=y;j++)hukuri *= 1+(double)r/100;
	sum *= hukuri;
      }

      if(max<sum){
	max=sum;
	bmax=b;
	sum=1;
      }
    }

    printf("%d\n",bmax);
  }
  return 0;
}