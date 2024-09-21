#include <stdio.h>
#include <math.h>

#define MOD 998244353

// Function to calculate the factorial of a number modulo M
long long factorial(long long n, long long M) {
  long long result = 1;
  for (long long i = 1; i <= n; i++) {
    result = (result * i) % M;
  }
  return result;
}

// Function to calculate the number of valid permutations modulo M
long long count_permutations(long long N, long long M) {
  // Calculate the total number of permutations
  long long total_permutations = factorial(2 * N, M);

  // Calculate the number of permutations that don't satisfy the condition
  long long invalid_permutations = 0;

  // Iterate over all possible values of i
  for (long long i = 0; i < 2 * N; i++) {
    // Calculate the range of valid values for P_i
    long long lower_bound = (long long)ceil(sqrt(N * N - i * i));
    long long upper_bound = (long long)floor(sqrt(4 * N * N - i * i));

    // If the range is empty, this value of i is invalid
    if (lower_bound > upper_bound) {
      invalid_permutations = (invalid_permutations + factorial(2 * N - 1, M)) % M;
    } else {
      // Calculate the number of invalid permutations for this value of i
      long long invalid_permutations_i = (upper_bound - lower_bound + 1) * factorial(2 * N - 1, M) % M;
      invalid_permutations = (invalid_permutations + invalid_permutations_i) % M;
    }
  }

  // Calculate the number of valid permutations
  long long valid_permutations = (total_permutations - invalid_permutations + M) % M;

  return valid_permutations;
}

int main() {
  long long N, M;
  scanf("%lld %lld", &N, &M);
  printf("%lld\n", count_permutations(N, M));
  return 0;
}