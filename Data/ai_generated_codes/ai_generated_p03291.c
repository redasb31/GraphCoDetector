#include <stdio.h>
#include <string.h>

#define MOD 1000000007

long long count_abc(char *s, int n) {
    long long count = 0;
    int a_count = 0, b_count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a_count++;
        } else if (s[i] == 'B') {
            b_count++;
            count += (long long)a_count * b_count;
        }
    }
    return count;
}

int main() {
    char s[100005];
    scanf("%s", s);

    int n = strlen(s);
    int q = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            q++;
        }
    }

    long long result = 0;
    for (int i = 0; i < (1 << q); i++) {
        char t[100005];
        strcpy(t, s);
        int j = 0;
        for (int k = 0; k < n; k++) {
            if (t[k] == '?') {
                if ((i >> j) & 1) {
                    t[k] = 'A';
                } else if (((i >> j) & 2) >> 1) {
                    t[k] = 'B';
                } else {
                    t[k] = 'C';
                }
                j++;
            }
        }
        result = (result + count_abc(t, n)) % MOD;
    }

    printf("%lld\n", result);
    return 0;
}