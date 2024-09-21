#include <stdio.h>

int main(void){
  int i;
  char o[50],e[50],oe[100];

  scanf("%s",&o);
  scanf("%s",&e);
  for(i = 0;i < (sizeof o);i++){
    oe[2*i] = o[i];
    oe[2*i+1] = e[i];
  }
  printf("%s\n",oe);
  return 0;
}
