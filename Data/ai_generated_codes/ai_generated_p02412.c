#include <stdio.h>

int main() {
  int n, x;

  // Loop through each dataset
  while (1) {
    // Read the input values for n and x
    scanf("%d %d", &n, &x);

    // Check if the input values are the terminal symbols
    if (n == 0 && x == 0) {
      break;
    }

    // Initialize the count of combinations
    int count = 0;

    // Iterate through the possible first integer
    for (int i = 1; i <= n; i++) {
      // Iterate through the possible second integer
      for (int j = i + 1; j <= n; j++) {
        // Iterate through the possible third integer
        for (int k = j + 1; k <= n; k++) {
          // Check if the sum of the three integers is equal to x
          if (i + j + k == x) {
            // Increment the count if the sum is equal to x
            count++;
          }
        }
      }
    }

    // Print the number of combinations
    printf("%d\n", count);
  }

  return 0;
}