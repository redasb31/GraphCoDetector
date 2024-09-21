// This code solves the magic card problem.
// The goal is to determine if M-kun can achieve a specific card arrangement
// through a series of multiplications by 2.

#include <stdio.h>

int main() {
  // Declare variables to store the values on the cards and the maximum number of operations.
  int A, B, C, K;

  // Read the input values from the user.
  scanf("%d %d %d %d", &A, &B, &C, &K);

  // Check if the magic can be successful by trying all possible combinations of operations.
  // The outer loop iterates over all possible operations.
  for (int i = 0; i <= K; i++) {
    // The inner loops iterate over all possible card choices for each operation.
    for (int j = 0; j <= i; j++) {
      // For each combination of operations, check if the conditions for successful magic are met.
      // This involves multiplying the values of the cards by 2 based on the chosen operations.
      if ((B * (1 << j) > A * (1 << (i - j))) && (C * (1 << (i - j)) > B * (1 << j))) {
        // If the conditions are met, print "Yes" and exit the program.
        printf("Yes\n");
        return 0;
      }
    }
  }

  // If no combination of operations leads to successful magic, print "No".
  printf("No\n");
  return 0;
}