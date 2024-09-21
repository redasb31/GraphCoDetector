#include <stdio.h>

#define MOD 1000000007

long long mod_inverse(long long a) {
  long long m = MOD, temp, q, x0 = 0, x1 = 1;
  while (a > 1) {
    q = a / m;
    temp = m;
    m = a % m;
    a = temp;
    temp = x0;
    x0 = x1 - q * x0;
    x1 = temp;
  }
  return (x1 + MOD) % MOD;
}

int main() {
  int B, W;
  scanf("%d %d", &B, &W);

  // Calculate probabilities for each piece
  for (int i = 1; i <= B + W; i++) {
    // Calculate the number of black and white pieces remaining after (i-1) pieces are eaten.
    int black_remaining = B - (i - 1) / 2;
    int white_remaining = W - (i - 1) / 2;
    // Calculate the probability of eating a black piece on the ith turn.
    long long probability = (black_remaining * mod_inverse(black_remaining + white_remaining)) % MOD;
    printf("%lld\n", probability);
  }

  return 0;
}