#include <stdio.h>

#define MOD 1000000007

// Function to calculate the number of pairs (a, b) satisfying the given conditions
long long countPairs(long long L) {
  // Initialize count to 0
  long long count = 0;
  // Iterate through all possible values of a
  for (long long a = 0; a <= L; a++) {
    // Calculate the maximum value of b for the current a
    long long maxB = L - a;
    // Iterate through all possible values of b
    for (long long b = 0; b <= maxB; b++) {
      // Check if a + b is equal to a XOR b
      if ((a + b) == (a ^ b)) {
        // Increment the count if the condition is satisfied
        count++;
      }
    }
  }
  // Return the count modulo 10^9 + 7
  return count % MOD;
}

int main() {
  // Input the value of L
  long long L;
  scanf("%lld", &L);

  // Calculate and print the count of pairs
  printf("%lld\n", countPairs(L));

  return 0;
}