#include <stdio.h>

int main(void) {
    long n, x, m;
    scanf("%ld%ld%ld", &n, &x, &m);
    int s[100001] = { 0 };
    long f = x;
    int first = 1;
    int last = 0;
    s[f] = 1;
    for(int i = 2;i <= n;i++) {
        f = (f * f) % m;
        if(s[f] != 0) {
            first = s[f];
            last = i;
            break;
        } else {
            s[f] = i;
            first = i;
        }
    }
    int t[100001] = { 0 };
    for(int i = 0;i < 100001;i++) {
        if(s[i] > 0) {
            t[s[i]-1] = i;
        }
    }
    if(first == n) {
        long result = 0;
        for(int i = 0;i < n;i++) {
            result += t[i];
        }
        printf("%ld\n", result);
    } else {
        first--, last--;
        long result = 0;
        for(int i = 0;i < first;i++) {
            result += t[i];
        }
        long x = 0;
        for(int i = first;i < last;i++) {
            x += t[i];
        }
        result += x * ((n - first) / (last - first));
        int d = (n - first) % (last - first);
        for(int i = 0;i < d;i++) {
            result += t[first + i];
        }
        printf("%ld\n", result);
    }
    return 0;
}
