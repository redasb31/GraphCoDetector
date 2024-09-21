#include<stdio.h>

int main()
{
    int n,x,i,sum=2,ans=0,cn=1,ar[1000];


    scanf("%d%d",&n,&x);

    for(i=1; i<=n; i++)
    {
        scanf("%d",&ar[i]);
    }

    for(i=1;i<=n;i++)
    {
        ans=((sum-1))+(ar[i]-1);
        sum=sum+ar[i];
        if(ans<=x)
        {
            cn++;
            ans=0;
        }
        else
        {
            ans=0;
        }
    }

    printf("%d\n",cn);

    return 0;
}