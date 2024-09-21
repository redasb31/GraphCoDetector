#include <stdio.h>
#include <math.h>

int main(void)
{

    long long  num;
    long long  money;
    long long  total = 0;
    
    scanf("%lld",&num);
    
    for (int i = 0; i < num; i++) {
        scanf("%lld",&money);
        total += money;
    }
    printf("%lld\n",(long long)floor(total / num));
    return 0;
}