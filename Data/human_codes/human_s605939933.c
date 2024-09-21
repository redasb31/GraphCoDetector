#include<stdio.h>
 int main(void)
{
 int a,b,c,x,y,u,z;

  scanf("%d%d%d",&a,&b,&c);
  if(a<=c && b<=c)
       x=c,u=b,z=a;
  else if (a<=b && c<=b)
        x=b,u=c,z=a;
  else if (b<=a && c<=a)
        x=a,u=a,z=b;
  y=(x*10)+u+z;
  printf("%d\n",y);
  return 0;
}
