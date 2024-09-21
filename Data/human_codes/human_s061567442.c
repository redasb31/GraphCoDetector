#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 n, m;
  scanf ("%" SCNi32 "%" SCNi32, &n, &m);
  const i32 LIM = 200000;
  i32 *dp = ALLOC (2 * LIM + 2, i32);
  i64 sum = 0;
  for (i32 i = 0; i < n; ++i) {
    i32 a;
    scanf ("%" SCNi32, &a);
    sum += a;
    dp[a]++;
  }
  for (i32 i = LIM - 1; i >= 0; --i) {
    dp[i] += dp[i + 1];
  }
  i32 *cnt = ALLOC (200000 + 1, i32);
  for (i32 i = 0; i < m; ++i) {
    i32 b;
    scanf ("%" SCNi32, &b);
    cnt[b]++;
  }
  i64 ans = (i64) sum * m;
  for (i32 i = 1; i <= LIM; ++i) {
    if (cnt[i] == 0) continue;
    for (i32 j = 0; j <= 200000; j += i) {
      ans -= (i64) cnt[i] * (dp[j] - dp[j + i]) * j;
    }
  }
  printf ("%" PRIi64 "\n", ans);
}

int main (void) {
  run();
  return 0;
}

