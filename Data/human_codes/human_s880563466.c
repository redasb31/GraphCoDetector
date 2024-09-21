#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check(char str[]);

int main(void){
  char str[16],substr[16];
  int i,j,k,l,maxans=0,tmp;
  scanf("%15s%*c",str);
  l=strlen(str);
  tmp=(1<<l);
  for(i=0;i<tmp;i++){
    k=0;
    for(j=0;j<l;j++)
      if((i>>j)&1) substr[k++]=str[j];
    substr[k]=0;
    if(check(substr)){
      //puts(substr);
      if(maxans<(j=strlen(substr))) maxans=j;
    }
  }
  printf("%d\n",maxans);
  return 0;
}

int check(char str[]){
  int i,j,k,l,flg=0;
  l=strlen(str);
  for(i=0;i<l;i++){
    if(strncmp(str+i,"iwi",3)==0 && flg==0){
      i+=2;
      flg=1;
      continue;
    }else if(str[i]=='i' || str[i]=='w') return 0;
  }
  if(flg==0) return 0;
  for(i=0;i<l;i++){
    if(str[i]=='(' && str[l-1-i]!=')') return 0;
    if(str[i]==')' && str[l-1-i]!='(') return 0;
    if(str[i]=='{' && str[l-1-i]!='}') return 0;
    if(str[i]=='}' && str[l-1-i]!='{') return 0;
    if(str[i]=='[' && str[l-1-i]!=']') return 0;
    if(str[i]==']' && str[l-1-i]!='[') return 0;
  }
  return 1;
}