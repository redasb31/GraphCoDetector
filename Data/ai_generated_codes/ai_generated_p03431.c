#include <stdio.h>

#define MOD 998244353

long long int mod_pow(long long int base, long long int exponent) {
  long long int result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = (result * base) % MOD;
    }
    base = (base * base) % MOD;
    exponent /= 2;
  }
  return result;
}

int main() {
  long long int N, K;
  scanf("%lld %lld", &N, &K);

  // If K is less than N, it's impossible for all chameleons to be red.
  if (K < N) {
    printf("0\n");
    return 0;
  }

  // The first N balls determine the color of each chameleon.
  // We can choose any combination of red and blue balls.
  long long int possibilities = mod_pow(2, N);

  // After the first N balls, all chameleons are either red or blue.
  // We need to make sure that all chameleons become red.
  // This means that the number of red balls thrown must be greater than
  // the number of blue balls thrown.
  // We can calculate this by considering the number of blue balls we can throw.
  // For example, if we throw 1 blue ball, we need to throw at least 2 red balls.
  // If we throw 2 blue balls, we need to throw at least 3 red balls, and so on.
  // This gives us a sequence of 1, 2, 3, ..., K-N, which represents the number of blue
  // balls we can throw.
  // The total number of possibilities for this is the sum of this sequence.
  long long int blue_balls = 0;
  for (long long int i = 0; i <= K - N; i++) {
    blue_balls = (blue_balls + i) % MOD;
  }

  // The total number of possibilities is the product of the two calculations above.
  long long int total_possibilities = (possibilities * blue_balls) % MOD;

  printf("%lld\n", total_possibilities);
  return 0;
}