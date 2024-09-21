#include<stdio.h>

int main(){

  int A,B,C,D;

  scanf("%d %d %d %d",&A,&B,&C,&D);
  if((A<=B)&&(C<=D)){

  if((A<=D&&D<=B)||(A<=C&&C<=B)){
    printf("Yes");
  }else{
    printf("No");
  }
}else{
  return 0;
}

}
