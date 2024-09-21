#include <stdio.h>
#include <limits.h>

// Function to calculate the minimum operations required to make A, B, and C equal
int minOperations(int A, int B, int C) {
  // Calculate the sum of A, B, and C
  int sum = A + B + C;

  // Calculate the target value (the value that A, B, and C should be equal to)
  int target = sum / 3;

  // Initialize the minimum operations to INT_MAX
  int minOps = INT_MAX;

  // Iterate through all possible combinations of operations
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      for (int k = 0; k <= 2; k++) {
        // Calculate the number of operations required for each combination
        int ops = abs(A - target + i) + abs(B - target + j) + abs(C - target + k);

        // If the current number of operations is less than the minimum, update minOps
        if (ops < minOps) {
          minOps = ops;
        }
      }
    }
  }

  // Return the minimum number of operations
  return minOps;
}

int main() {
  // Read the input values
  int A, B, C;
  scanf("%d %d %d", &A, &B, &C);

  // Calculate and print the minimum number of operations
  printf("%d\n", minOperations(A, B, C));

  return 0;
}