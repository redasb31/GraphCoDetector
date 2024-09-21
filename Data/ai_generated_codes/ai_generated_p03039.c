#include <stdio.h>

#define MOD 1000000007

long long int fact(long long int n) {
  if (n == 0) {
    return 1;
  }
  return (n * fact(n - 1)) % MOD;
}

long long int mod_inverse(long long int a) {
  // Using Fermat's Little Theorem
  return (long long int)pow(a, MOD - 2) % MOD;
}

long long int nCr(long long int n, long long int r) {
  return (fact(n) * mod_inverse(fact(r)) * mod_inverse(fact(n - r))) % MOD;
}

int main() {
  long long int N, M, K;
  scanf("%lld %lld %lld", &N, &M, &K);

  // Calculate the total number of ways to choose K squares
  long long int total_arrangements = nCr(N * M, K);

  // Calculate the cost of each individual arrangement
  long long int cost = 0;
  for (long long int i = 1; i <= K - 1; i++) {
    for (long long int j = i + 1; j <= K; j++) {
      // The absolute difference between the row indices of the squares
      cost += (abs(i - j) % MOD); 
      // The absolute difference between the column indices of the squares
      cost += (abs(i - j) % MOD);
    }
  }

  // Multiply the cost by the number of arrangements
  long long int total_cost = (cost * total_arrangements) % MOD;

  printf("%lld\n", total_cost);

  return 0;
}