#include <stdio.h>

int main()
{
    long long N, k;
    long long a, b;
    long long i, j;

    scanf("%lld %lld", &N, &k);

    a = 0; b = 0;
    for(i = 0; i < N - 1; i++){
        j = b/(k-1);
        while(1){
            if(k == 2){
                if(++j == b+2) break;
            }else{
                if(++j > b/(k-1)+k/(k-1)) break;
            }
        }
        a = --j;
        b += a;
    }

    printf("%lld\n", b);

    return 0;
}

