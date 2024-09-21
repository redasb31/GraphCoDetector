#include<stdio.h>
int main()
{
    long long int N,M;
    long long int k;
    scanf("%lld %lld",&N,&M);
    if(N==1)
        printf("%lld\n",M-2);
    else if(N==2)
        printf("0\n");
    else
    {
        k=M*N-M*2-N*2+4;
        printf("%lld\n",k);
    }
    return 0;
}
