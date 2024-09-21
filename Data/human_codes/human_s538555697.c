#include<stdio.h>
int main()
{
    int a,b,c,sum;
    scanf("%d %d %d",&a,&b,&c);
    if(a==b&&b==c)
    {
        sum=2*a;
        printf("%d",sum);
    }
    else
    {
        if(a<b&&b<c)
            {
                sum=a+b;
                printf("%d\n",sum);

            }
        if(a<b&&c<b)
            {
                sum=a+c;
                printf("%d\n",sum);

            }
        if(b<a&&c<a)
            {
                sum=b+c;
                printf("%d\n",sum);

            }

        if(a==b&&b<c)
        {
            sum=b+a;
            printf("%d\n",sum);
        }
        if(a==b&&b>c)
        {
            sum=b+c;
            printf("%d\n",sum);
        }
        if(b==c&&a>c)
        {
            sum=b+c;
            printf("%d\n",sum);
        }
        if(b==c&&a<c)
        {
            sum=b+a;
            printf("%d\n",sum);
        }
        if(a==c&&a<b)
        {
            sum=a+c;
            printf("%d\n",sum);
        }
        if(a==c&&a>b)
        {
            sum=b+c;
            printf("%d\n",sum);
        }


    }
    return 0;

}
