#include<stdio.h>
#include<string.h>

int main(void)
{
  char str[10000000];
  scanf("%s",str);
  int l=0,i;
  l = strlen(str);
  //01010101010になりたい
  int num1=0;
  for(i = 0;i <l;i ++)
  {
    if(i%2==0)
    {
      num1 += (1-str[i]);
    }else
    {
      num1 += (str[i]-0);
    }
  }
  //101010101010101010になりたい
  int num2=0;
  for(i = 0;i <l;i ++)
  {
    if(i%2==0)
    {
      num2 += (str[i]-0);
    }else
    {
      num2 += (1-str[i]);
    }
  }
  //101010101010101010になりたい
  if(num1>=num2)
  {
    printf("%d",num2);
  }else
  {
    printf("%d",num1);
  }
  
  return 0;
}