#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

const i32 mod = 1000000007;

i32 mod_pow (i32 r, i32 n) {
  i32 t = 1;
  while (n > 0) {
    if (n & 1) t = (i64) t * r % mod;
    r = (i64) r * r % mod;
    n >>= 1;
  }
  return t;
}

i32 fact (i32 n) {
  i32 res = 1;
  for (i32 i = 1; i <= n; ++i) {
    res = (i64) res * i % mod;
  }
  return res;
}

i32 comb (i32 n, i32 k) {
  if (!(0 <= k && k <= n)) return 0;
  i32 nu = 1;
  i32 de = 1;
  for (i32 i = 1; i <= k; ++i) {
    nu = (i64) nu * (n + 1 - i) % mod;
    de = (i64) de * i % mod;
  }
  return (i64) nu * mod_pow (de, mod - 2) % mod;
}

void run (void) {
  i32 n, k;
  scanf ("%" SCNi32 "%" SCNi32, &n, &k);
  i32 ans = 0;
  for (i32 i = k, sign = 1; i > 0; --i, sign = -sign) {
    ans = (ans + mod + (i64)sign * comb (k, i) * mod_pow (i, n) % mod) % mod;
  }
  ans = (i64) ans * mod_pow (fact (k), mod - 2) % mod;
  printf ("%" PRIi32 "\n", ans);
}

int main (void) {
  run();
  return 0;
}

