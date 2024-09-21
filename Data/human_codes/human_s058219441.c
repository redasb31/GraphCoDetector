#include<stdio.h>
int main(){
  int a,b,N;
  int start[100],finish[100];
  int i,flag=0;
  
  scanf("%d%d",&a,&b);
  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d%d",&start[i],&finish[i]);
    if((start[i]<=a && a<finish[i]) || (start[i]<b && b<finish[i]))
      flag=1;
  }
  printf("%d\n",flag);
   return 0;
}