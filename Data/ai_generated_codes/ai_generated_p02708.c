#include <stdio.h>

#define MOD 1000000007

int main() {
  // Input: N and K
  long long N, K;
  scanf("%lld %lld", &N, &K);

  // Calculate the number of possible sums
  long long result = 0;
  if (K == N + 1) {
    // Choosing all integers, only one possible sum
    result = 1;
  } else {
    // Calculate the number of possible sums based on K and N
    for (long long i = K; i <= N + 1; i++) {
      // The sum can take values from K to N+1
      result = (result + i) % MOD;
    }
  }

  // Output the result
  printf("%lld\n", result);

  return 0;
}