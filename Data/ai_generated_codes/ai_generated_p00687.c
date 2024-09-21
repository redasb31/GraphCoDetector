#include <stdio.h>
#include <stdbool.h>

// Function to check if a number can be represented by the given formula
bool can_be_represented(int n, int a, int b) {
  // Iterate through all possible values of i and j
  for (int i = 0; i * a <= n; i++) {
    for (int j = 0; i * a + j * b <= n; j++) {
      if (i * a + j * b == n) {
        return true; // Number can be represented
      }
    }
  }
  return false; // Number cannot be represented
}

int main() {
  int n, a, b;
  // Read input until the last line with all zeros
  while (scanf("%d %d %d", &n, &a, &b) == 3 && (n != 0 || a != 0 || b != 0)) {
    // Initialize count of unrepresentable numbers
    int count = 0;
    // Iterate through all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
      // Check if the current number can be represented
      if (!can_be_represented(i, a, b)) {
        count++; // Increment count if not representable
      }
    }
    printf("%d\n", count); // Print the count
  }
  return 0;
}