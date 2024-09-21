/*
AizuOnline A0233
Title
@kankichi573
*/
#include <stdio.h>
int n;
//
int solve100(int n)
{
        if(n < 10)
                return(n);
        else
                return((n % 10) + (100 - (n/10)*10));
}

int solve_p(int n)
{
        int c;
        
        if(n==0)
                return(0);
        c=n/100;
        if((n % 100) >= 10)
                c++;
        //printf(":%d\n",c);
        return(100*solve(c)+solve100(n % 100));
}

int solve100_n(int n)
{
        int c,c2;

        c=n/10;
        if((n % 10)>0)
                c++;
        c2=(10 - (n%10))%10;
        return(c*10+c2);
}

int solve_n(int n)
{
        int c1,c2;

        if(n==0)
                return(0);
        c2=n%100;
        c1=n/100;
        if(c2>90)
        {       c2=(10-c2%10)%10;
                c1++;
                return(100*solve_n(c1)+c2);
        }
        else
                return(100*solve_n(c1)+solve100_n(c2));
}
int solve(int n)
{
        if(n>=0)
                return(solve_p(n));
        else
                return(solve_n(-n));
}
main()
{
        int n;

        while(EOF!=scanf("%d",&n) && n)
                printf("%d\n",solve(n));
        return(0);
}