#include <stdio.h>
#include <math.h>

// Function to calculate the minimum sum of squares of differences
int minSumOfSquares(int a, int b) {
  int minSum = INT_MAX;
  // Iterate through all possible factorizations of a
  for (int a1 = 1; a1 * a1 <= a; a1++) {
    if (a % a1 == 0) {
      int a2 = a / a1;
      // Iterate through all possible factorizations of b
      for (int b1 = 1; b1 * b1 <= b; b1++) {
        if (b % b1 == 0) {
          int b2 = b / b1;
          // Calculate the sum of squares of differences for the current factorization
          int sum = (a2 - a1) * (a2 - a1) + (b1 - a2) * (b1 - a2) + (b2 - b1) * (b2 - b1);
          // Update the minimum sum if necessary
          if (sum < minSum) {
            minSum = sum;
          }
        }
      }
    }
  }
  return minSum;
}

int main() {
  int a, b;
  // Read input until encountering two zeros
  while (scanf("%d %d", &a, &b) == 2 && (a != 0 || b != 0)) {
    // Calculate and print the minimum sum of squares
    printf("%d\n", minSumOfSquares(a, b));
  }
  return 0;
}