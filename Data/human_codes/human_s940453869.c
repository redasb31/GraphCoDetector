#include <stdio.h>

typedef long long int ll;

int solve(ll n) {
    switch(n % 4) {
        case 0: return n; break;
        case 1: return 1; break;
        case 2: return n+1; break;
        case 3: return 0; break;
    }
}

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("%d\n", solve(a-1) ^ solve(b));
    return 0;
}
