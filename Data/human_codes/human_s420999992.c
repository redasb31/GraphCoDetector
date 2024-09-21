
#include <stdio.h>

int main()
{
  unsigned long long int n,i,x,sum=0,count=0,flag=0;
   char a[1000000];
   
   
scanf("%s",a);
for(i=0;i<strlen(a)-2;i++)
{
    if(a[i]!=a[i+2])
    {
     count++;   
    }
}
if(count%2==0)
{
    printf("Second");
}else{
    printf("First");
}
    return 0;
}
