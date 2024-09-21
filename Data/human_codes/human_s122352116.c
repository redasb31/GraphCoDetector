#include<stdio.h>

int main()
{
    int n,p,a,b,x,y,z,i,f=0;
    char d;

    scanf("%d%c%d",&p,&d,&n);
    n=n/1000;
    a=n-p;
    if(a==0)
        printf("0 0 %d",p);
    else if(a<0)
        printf("-1 -1 -1");
    else
    {
        for(i=0;i<n;i++)
        {
            y=a-(i*9);
            if(y%4==0)
            {
                b=i+y;
                if(b<=p)
                {
                    z=p-b;
                    b=(i*10)+(y*5)+z;
                    if(b==n)
                    {
                        f=1;
                        break;
                    }
                }
            }
        }

        if(f)
            printf("%d %d %d",i,y,z);
        else
            printf("-1 -1 -1");
    }
}
