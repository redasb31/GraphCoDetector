#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

// Function to calculate factorial modulo MOD
long long factorial(int n) {
  long long fact = 1;
  for (int i = 2; i <= n; i++) {
    fact = (fact * i) % MOD;
  }
  return fact;
}

// Function to calculate the number of ways to form pairs
long long countPairs(int n, int *heights) {
  // Calculate the factorial of 2N
  long long totalPairs = factorial(2 * n);

  // Count the number of pairs with the same height
  int *count = (int *)calloc(100001, sizeof(int));
  for (int i = 0; i < 2 * n; i++) {
    count[heights[i]]++;
  }

  // Calculate the factorial of the count of each height
  long long sameHeightPairs = 1;
  for (int i = 1; i <= 100000; i++) {
    if (count[i] > 1) {
      sameHeightPairs = (sameHeightPairs * factorial(count[i])) % MOD;
    }
  }
  free(count);

  // Calculate the number of valid pairs
  long long validPairs = (totalPairs / sameHeightPairs) % MOD;
  return validPairs;
}

int main() {
  int n;
  scanf("%d", &n);

  int *heights = (int *)malloc(2 * n * sizeof(int));
  for (int i = 0; i < 2 * n; i++) {
    scanf("%d", &heights[i]);
  }

  // Calculate and print the number of valid pairs
  long long result = countPairs(n, heights);
  printf("%lld\n", result);

  free(heights);
  return 0;
}