#include<stdio.h>
#include<string.h>
int main(){
  char s[100000]={};
  int i;
  scanf("%s",s);
  int a;
  a=strlen(s);
  int ans=0;
  for(i=1;i<a;i++){
    if(s[i]!=s[i-1]){
      ans++;
    }
  }

  // printf("%d\n",a);
  printf("%d\n",ans);
  return 0;
}