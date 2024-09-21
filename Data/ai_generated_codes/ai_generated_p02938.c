#include <stdio.h>

#define MOD 1000000007

// Function to calculate the number of pairs (x, y) satisfying the condition
long long countPairs(long long L, long long R) {
  long long count = 0;

  // Iterate through all possible values of x
  for (long long x = L; x <= R; x++) {
    // Calculate the maximum value of y for the given x
    long long yMax = R / x * x + x - 1; // y must be less than or equal to R and satisfy the condition y % x = x - 1

    // Check if the maximum value of y is within the range [L, R]
    if (yMax >= L && yMax <= R) {
      // Calculate the number of valid y values for the given x
      count = (count + (yMax - x + 1)) % MOD;
    }
  }

  return count;
}

int main() {
  long long L, R;

  // Read the input values
  scanf("%lld %lld", &L, &R);

  // Calculate and print the number of pairs
  printf("%lld\n", countPairs(L, R));

  return 0;
}