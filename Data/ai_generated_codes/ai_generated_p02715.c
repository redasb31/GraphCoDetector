#include <stdio.h>

// Modulo value
#define MOD 1000000007

// Function to calculate the sum of GCDs for all sequences
long long gcdSum(int n, int k) {
  // Base case: If the sequence length is 1, the GCD is the only element
  if (n == 1) {
    return k;
  }

  // Recursive step: Calculate the sum for shorter sequences and combine
  long long sum = 0;
  for (int i = 1; i <= k; i++) {
    // Calculate the sum for sequences starting with 'i'
    sum = (sum + (gcdSum(n - 1, k) * i) % MOD) % MOD;
  }

  return sum;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k); // Read input values

  // Calculate and print the sum of GCDs
  printf("%lld\n", gcdSum(n, k));

  return 0;
}