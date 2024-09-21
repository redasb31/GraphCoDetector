#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MOD 1000000007

long long int fac[1000000], finv[1000000], inv[1000000];

void init(){
    fac[0] = 1;
    fac[1] = 1;
    finv[0] = 1;
    finv[1] = 1;
    inv[1] = 1;
    for(int i=2; i<1000000; i++){
        fac[i] = fac[i-1]*i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

long long int combination(long long int n,long long int r){
    if(r==0||r==n){
        return 0;
    }
    if(n < r){
        return 0;
    }
    return (fac[n] * (finv[r] * finv[n-r] % MOD)) % MOD;
}
int main(){
    long long int x, y;
    scanf("%lld%lld", &x, &y);
    long long int ans = 0;
    init();
    for(long long int i=0; i<=x; i++){
        if((x + y) % 3 != 0){
            break;
        }
        long long int j = (x - i)/2;
        if(2*i + j == y && (x-i) % 2 == 0){
            ans += combination((j+i)%MOD, j%MOD);
            ans = ans % MOD;
        }
    }
    printf("%lld\n", ans);

    return 0;
}
