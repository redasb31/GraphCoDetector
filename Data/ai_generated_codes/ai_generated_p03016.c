#include <stdio.h>

// Function to calculate the remainder when a large number is divided by a smaller number
long long modulo(long long num, long long mod) {
  return ((num % mod) + mod) % mod; // Ensures positive remainder
}

int main() {
  long long L, A, B, M; // Declare variables for input

  // Read input from the standard input
  scanf("%lld %lld %lld %lld", &L, &A, &B, &M);

  long long result = 0; // Variable to store the final result
  long long term = A; // Variable to store the current term in the arithmetic progression

  // Loop through each term in the arithmetic progression
  for (long long i = 0; i < L; i++) {
    // Calculate the remainder of the current term divided by M
    long long current_term_mod = modulo(term, M);

    // Calculate the number of digits in the current term
    long long digits = 0;
    long long temp = current_term_mod;
    while (temp > 0) {
      digits++;
      temp /= 10;
    }

    // Multiply the result by 10^digits (effectively shifting the result by 'digits' places to the left)
    result = modulo(result * modulo(10, digits), M);

    // Add the current term's remainder to the result
    result = modulo(result + current_term_mod, M);

    // Move to the next term in the arithmetic progression
    term += B;
  }

  // Print the final result (the remainder after concatenating all terms and dividing by M)
  printf("%lld\n", result);

  return 0;
}