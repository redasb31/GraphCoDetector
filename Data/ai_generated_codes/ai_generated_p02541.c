// This C code solves the problem of finding the minimum positive integer k
// such that the sum of integers from 1 to k is a multiple of a given integer N.

#include <stdio.h>

int main() {
  long long N; // Declare N as a long long to handle large input values

  // Read the input value for N from standard input
  scanf("%lld", &N);

  // Initialize variables to store the sum and the current value of k
  long long sum = 0; 
  long long k = 1;

  // Iterate until the sum is a multiple of N
  while (sum % N != 0) {
    // Add the current value of k to the sum
    sum += k;
    // Increment k for the next iteration
    k++;
  }

  // Print the minimum value of k that satisfies the condition
  printf("%lld\n", k - 1);

  return 0; 
}