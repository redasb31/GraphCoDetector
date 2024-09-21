#include <stdio.h>

// Function to calculate the number of partitions of p/q into unit fractions
// satisfying the given constraints
int count_partitions(int p, int q, int a, int n) {
  // Create a table to store the number of partitions for each fraction
  int partitions[n + 1][a + 1];
  // Initialize all entries to 0
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= a; j++) {
      partitions[i][j] = 0;
    }
  }

  // Base case: 0 partitions for fraction 0/q
  partitions[0][1] = 1;

  // Iterate through the number of unit fractions
  for (int i = 1; i <= n; i++) {
    // Iterate through the product of denominators
    for (int j = 1; j <= a; j++) {
      // Iterate through the denominators of the unit fractions
      for (int k = 1; k <= j; k++) {
        // Check if the current unit fraction (1/k) contributes to the partition
        if (k * q <= p * j) {
          // Update the number of partitions
          partitions[i][j] += partitions[i - 1][j / k];
        }
      }
    }
  }

  // Return the number of partitions for the fraction p/q
  return partitions[n][a];
}

int main() {
  int p, q, a, n;
  // Read input until the terminator is encountered
  while (scanf("%d %d %d %d", &p, &q, &a, &n) == 4 && (p != 0 || q != 0 || a != 0 || n != 0)) {
    // Calculate and print the number of partitions
    printf("%d\n", count_partitions(p, q, a, n));
  }
  return 0;
}