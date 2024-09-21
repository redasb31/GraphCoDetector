#include <stdio.h>
#include <string.h>
int main(){
  int result=999;
  int i,tmp;
  char s[11];
  
  scanf("%s",s);
  
  for(i=0;i<strlen(s)-2;i++){
    tmp=(s[i]-'0')*100;
    tmp+=(s[i+1]-'0')*10;
    tmp+=s[i+2]-'0';
    tmp=753-tmp;
    if(tmp<0) tmp=0-tmp;
    if(tmp<result) result=tmp;
  }
  
  printf("%d",result);
}