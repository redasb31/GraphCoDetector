#include<stdio.h>
int main()
{
    int r,c,a;
    scanf("%d%d",&r,&c);
    if(r>=2 && r<=100 && c>=2 && c<=100)
    {


    a=(r-1)*(c-1);
    printf("%d\n",a);
    }
     return 0;
}
