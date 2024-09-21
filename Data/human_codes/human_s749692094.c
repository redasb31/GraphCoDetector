#include<stdio.h>
int main()
{
    long long int a,b,c,d;
    long long int max,s1,s2,s3,s4;
    scanf("%l64d%l64d%l64d%l64d",&a,&b,&c,&d);
    s1=a*c;
    s2=a*d;
    s3=b*c;
    s4=b*d;
    max=s1;
    if(max<s2){max=s2;}
    if(max<s3){max=s3;}
    if(max<s4){max=s4;}
    printf("%lld\n",max);
    return 0;

}
