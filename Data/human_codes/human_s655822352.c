#include<stdio.h>
#define MAX 100

int main(){
  int x1=0,x2=0,x3,x4,y1=0,y2,y3=0,y4,i=0,t,L[MAX];
  for(int i=0;i<3;i++){
    scanf("%d",&L[i]);
  }
  x3=x4=L[0];
  y2=y4=L[1];
  t=L[2];
  for(i=0;i<t;i++){
    for(int j=0;j<3;j++){
      scanf("%d",&L[j]);
    }
    switch(L[2]){
      case 1:
      if(x1<=L[0]){
      x1=x2=L[0];
      }
      break;
      case 2:
      if(x3>=L[0]){
      x3=x4=L[0];
      }
      break;
      case 3:
      if(y1<=L[1]){
      y1=y3=L[1];
      }
      break;
      case 4:
      if(y2>=L[1]){
      y2=y4=L[1];
      }
      break;
    }
  }
  if((x3-x1)*(y4-y3)<=0){
    printf("0");
  }else{
    printf("%d",(x3-x1)*(y4-y1));
  }
  return 0;
}
