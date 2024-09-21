#include <stdio.h>
int main(void){
  char s[10];
  int judge=1;
  scanf("%s",s);
  if(s[0]!='Y') judge=0;
  if(s[1]!='A') judge=0;
  if(s[2]!='K') judge=0;
  if(s[3]!='I') judge=0;
  if(judge==1) printf("Yes\n");
  else printf("No\n");
  return(0);
}
