#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the factorial of a number
long long factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return (n * factorial(n - 1)) % MOD;
}

// Function to calculate the number of permutations with a given oddness
long long count_permutations(int n, int k) {
  // Base case: If k is less than 0, there are no permutations
  if (k < 0) {
    return 0;
  }

  // Base case: If k is 0, there is only one permutation (the identity permutation)
  if (k == 0) {
    return 1;
  }

  // Calculate the factorial of n
  long long fact_n = factorial(n);

  // Initialize the count of permutations to 0
  long long count = 0;

  // Iterate over all possible values of the first element
  for (int i = 1; i <= n; ++i) {
    // Calculate the oddness of the permutation if the first element is i
    int oddness = abs(i - 1);

    // Recursively calculate the number of permutations for the remaining elements
    count = (count + count_permutations(n - 1, k - oddness)) % MOD;
  }

  // Return the total count of permutations
  return (fact_n * count) % MOD;
}

int main() {
  int n, k;

  // Read the input values
  scanf("%d %d", &n, &k);

  // Calculate and print the number of permutations
  printf("%lld\n", count_permutations(n, k));

  return 0;
}