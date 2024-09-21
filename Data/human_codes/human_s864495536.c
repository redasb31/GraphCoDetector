#include<stdio.h>
#include<stdlib.h>
int main(){
  int x,y,i,d=0,a=0,b=0;
  char s[100010];
  scanf("%s",s);
  for(i=0;s[i];i++)s[i]-'T'?d?(b++):(a++):(d=1-d);
  for(i=0;s[i]&&s[i]-'T';i++);
  scanf("%d %d",&x,&y);
  //printf("%d %d %d\n",a,b,i);
  printf("%s\n",(x>a||y>b||i+i-x>a||abs(x)%2-a%2||abs(y)%2-b%2)?"No":"Yes");
  return 0;
}
