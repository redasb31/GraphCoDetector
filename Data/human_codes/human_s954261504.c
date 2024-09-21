#include <stdio.h>

int int main(){

  char s[3];
  int count=0;

  scanf("%s",s);

  for(int i=0;i<3;i++){
    if(s[i]=='o') count++;
  }

  printf("%d\n",700+(100*count));
  
  return 0;
}