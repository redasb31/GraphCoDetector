#include<stdio.h>

int main(){

    unsigned long long a,b,c,d;
    scanf("%ld %ld %ld %ld",&a,&b,&c,&d);
    
    unsigned long long count=0;
    count += b-a+1;
    int x=c*d;
    count -= (b/c)-((a-1)/c)+(b/d)-((a-1)/d);

    int r = d % c;
    while(r!=0){
        d=c;
        c=r;
        r=d%c;
    }

    count += (b/(x/c))-((a-1)/(x/c));
        
    printf("%ld\n",count);

    return 0;
}