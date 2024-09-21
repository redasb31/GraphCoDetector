#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

i32 mod = 1000000007;

i32 inv (i32 a) {
  i32 t = 1;
  while (a > 1) {
    t = (i64) t * (mod - mod / a) % mod;
    a = mod % a;
  }
  return t;
}

i32 mod_pow (i32 r, i32 n, i32 mod) {
  i32 t = 1;
  i32 s = r;
  while (n > 0) {
    if (n & 1) t = (i64) t * s % mod;
    s = (i64) s * s % mod;
    n >>= 1;
  }
  return t;
}

i32 *fact = NULL;
i32 *iFact = NULL;
void init_fact (const i32 n) {
  fact = (i32 *) calloc (n + 1, sizeof (i32));
  fact[0] = 1;
  for (i32 i = 1; i <= n; ++i) {
    fact[i] = (i64) i * fact[i - 1] % mod;
  }
  iFact = (i32 *) calloc (n + 1, sizeof (i32));
  iFact[n] = inv (fact[n]);
  for (i32 i = n - 1; i >= 0; --i) {
    iFact[i] = (i64) (i + 1) * iFact[i + 1] % mod;
  }
}

i32 comb (i32 n, i32 k) {
  if (!(0 <= k && k <= n)) return 0;
  return (i64) fact[n] * iFact[k] % mod * iFact[n - k] % mod;
}

#define POS(i, j) ((i) * (n + 1) + (j))

void run (void) {
  i32 n;
  scanf ("%" SCNi32 "%" SCNi32, &n, &mod);
  init_fact (n);
  i32 *dp = (i32 *) calloc ((n + 1) * (n + 1), sizeof (i32));
  for (i32 i = 0; i <= n; ++i) {
    dp[POS(0, i)] = 1;
  }
  for (i32 i = 1; i <= n; ++i) {
    for (i32 j = 1; j <= n; ++j) {
      dp[POS(i, j)] = (dp[POS(i, j - 1)] + dp[POS(i - 1, j - 1)] + (i64) i * dp[POS(i, j - 1)]) % mod;
    }
  }
  i32 ans = 0;
  for (i32 i = 0, sign = 1; i <= n; ++i, sign *= -1) {
    i32 way = 0;
    i32 p = mod_pow (2, n - i, mod);
    for (i32 j = 0, a = 1; j <= i; ++j, a = (i64) a * p % mod) {
      way = (way + (i64) dp[POS(j, i)] * a)% mod;
    }
    i32 x = (i64) comb (n, i) * way % mod;
    i32 y = mod_pow (2, mod_pow (2, n - i, mod - 1), mod);
    ans = (ans + (i64) sign * x * y % mod + mod) % mod;
  }
  printf ("%" PRIi32 "\n", ans);
}

int main (void) {
  run();
  return 0;
}
