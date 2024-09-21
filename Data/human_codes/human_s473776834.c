#include <stdio.h>

int main()
{
    long int n,a,b,c,count,i;
    scanf("%ld %ld %ld\n",&n,&a,&b);
    count=0;
    for(i=0;i<n;i++)
    {
        scanf("%ld",&c);
        if(c<=a ||  c>=b)
        {
            count++;
        }
    }
    printf("%ld\n",count);

    return 0;
}