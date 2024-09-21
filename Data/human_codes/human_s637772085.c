#include <stdio.h>
#include <stdint.h>

#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

char s[301];
int64_t a[302];
int64_t dp[301][301];

int main() {
    scanf("%s", s);

    int64_t t = 0, n = 1;
    for (char* p = s; *p != 0; ++p) {
        if (*p == '0') {
            a[n++] = t;
        } else {
            ++t;
        }
    }
    a[n++] = t;

    int64_t k;
    scanf("%ld", &k);
    k = min(k, a[n - 1]);

    int64_t M = 998244353L;

    int64_t mk = 0;
    dp[0][0] = 1;
    for (int64_t i = 0; i < n - 1; ++i) {
        for (int64_t j = mk; j >= 0; --j) {
            auto r = min(k - j, a[i + 1] - a[i]);
            auto mc = a[n - 1]  - a[i + 1];
            for (int64_t b = 1; b <= mc + r; ++b) {
                for (int64_t c = max(0L, b - r); c < b && c <= mc; ++c) {
                    int64_t w = j + b - c;
                    dp[w][c] += dp[j][b];
                    if (dp[w][c] >= M) {
                        dp[w][c] -= M;
                    }
                }
            }

            for (int64_t c = 1; c <= a[n - 1] - a[i + 1]; ++c) {
                dp[j][c] += dp[j][c - 1];
                if (dp[j][c] >= M) {
                    dp[j][c] -= M;
                }
            }
        }
        mk = min(k, mk + a[i + 1] - a[i]);
    }

    int64_t ans = 0;
    for (int64_t i = 0; i <= mk; ++i) {
        ans += dp[i][0];
    }

    printf("%ld\n", ans % M);
}
