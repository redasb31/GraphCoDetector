#include <stdio.h>

int main(void) {
    long long n,a[100000],i,ans = 0;
    scanf("%lld",&n);
    for (i = 0;i < n;i++) {
        scanf("%lld",&a[i]);
        ans += a[i];
    }
    ans = (ans * (1 + n) * n / 2) % 1000000007; 
    return 0;
}
