#include<stdio.h>
int main()
{
    int A,B,C,D;
    scanf("%d %d %d %d",&A,&B,&C,&D);

    if(A*B>C*D)
    {
        printf("%d ",A*B);
    }
     else if(A*B<C*D)
    {
        printf("%d ",C*D);
    }
     else
    {
        printf("%d ",A*B);
    }



}
