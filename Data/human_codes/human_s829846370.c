#include<stdio.h>
int main(void){
  char s[5];
  scanf("%s",s);
  if(s[0]=='M')
    printf("6\n");
  else if(s[0]=='T')
    printf("5\n");
  else if(s[0]=='W')
    printf("4\n");
  else if(s[0]=='T')
    printf("3\n");
  else if(s[0]=='F')
    printf("2\n");
  else{
    if(s[1]=='A')
      printf("1\n");
    else if(s[1]=='U')
      printf("7\n");
  }

  return 0;}
