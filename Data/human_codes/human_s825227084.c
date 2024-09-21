#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 10000
int main()
{
   int n,a[N],b,x,m,i;
   long int  t;
   scanf("%d%d",&n,&m);
   for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    t=0;
   for(i=0;i<n-1;i++)
   {
       if(a[i]+a[i+1]>m)
       {
           if(a[i]>=m)
           {
               t=t+a[i+1];
               t=t+a[i]-m;
             a[i+1]=0;
             a[i]=m;

           }
         else
         {
             t+=a[i+1]-(m-a[i]);
             a[i+1]=m-a[i];
         }

       }

   }

printf("%ld",t);


    return 0;
}
