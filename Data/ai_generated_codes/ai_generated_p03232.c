#include <stdio.h>

#define MOD 1000000007

long long int fact(int n) {
  long long int result = 1;
  for (int i = 2; i <= n; i++) {
    result = (result * i) % MOD;
  }
  return result;
}

int main() {
  int N;
  scanf("%d", &N);

  long long int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }

  // Calculate the sum of all weights
  long long int total_weight = 0;
  for (int i = 0; i < N; i++) {
    total_weight = (total_weight + A[i]) % MOD;
  }

  // Calculate the sum of all costs for all permutations
  long long int sum_cost = 0;
  for (int i = 0; i < N; i++) {
    // Calculate the cost of removing the i-th block
    long long int cost = 0;
    for (int j = i; j < N; j++) {
      cost = (cost + A[j]) % MOD;
    }

    // Multiply the cost by the number of permutations where the i-th block is removed at this position
    sum_cost = (sum_cost + cost * fact(N - i - 1) * fact(i)) % MOD;
  }

  // Multiply the sum of costs by the number of permutations of all N blocks
  sum_cost = (sum_cost * fact(N)) % MOD;

  printf("%lld\n", sum_cost);
  return 0;
}