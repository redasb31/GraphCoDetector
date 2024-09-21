/*
  AOJ #3100
  Strange Plants
  @kankichi57301
 */
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int x,a,b,n;
char s[10];
int main()
{
  int i;
  
  scanf("%d %d %d",&x,&a,&b);
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%s",s);
    if(0==strcmp(s,"nobiro"))
      x = max(0,x+a);
    else if(0==strcmp(s,"tidime"))
      x = max(0,x+b);
    else if(0==strcmp(s,"karero"))
      x = 0;
    //printf("%d\n",x);
  }

  printf("%d\n",x);
  return (0);
}

