#include<stdio.h>
#include<math.h>
long long int s,i,a,b,a1,b1;
int main()
{

    scanf("%lld",&s);
    while(s!=0)
    {
       s=s*2;
       for(i=1;i<=sqrt(s);i=i+1)
       {
           if(s%i==0)
           {
               b=i;
               a=(s/i)-i+1;
               a=a/2;
               if((a*2+b-1)*b==s)
               {
                   a1=a;
                   b1=b;
               }
           }
       }
       printf("%lld %lld\n",a1,b1);
       scanf("%lld",&s);
    }
    return 0;
}

