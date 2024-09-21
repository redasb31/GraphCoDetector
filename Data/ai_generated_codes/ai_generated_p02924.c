#include <stdio.h>

int main() {
  long long int N; // Declare N as a long long int to handle large values

  // Input N
  scanf("%lld", &N);

  // Calculate the maximum sum
  long long int maxSum = 0; // Initialize maxSum to 0
  for (long long int i = 1; i <= N; i++) {
    // For each number i, the maximum remainder is i - 1
    maxSum += (i - 1);
  }

  // Print the maximum sum
  printf("%lld\n", maxSum);

  return 0;
}