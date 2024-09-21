#include<stdio.h>
int main()
{
    unsigned long long int x, ans;
    scanf("%lld", &x);
    ans = x / 11;
    ans *= 2;
    x %= 11;
    if (x > 0)
    {
        if (x <= 6)
            ans++;
        else
            ans += 2;
    }
    printf("%lld\n", ans);
    return 0;
}