#include <stdio.h>

// Function to calculate the number of ways to select coins
int count_ways(int A, int B, int C, int X) {
  // Initialize the number of ways to 0
  int count = 0;

  // Iterate over all possible combinations of coins
  for (int i = 0; i <= A; i++) {
    for (int j = 0; j <= B; j++) {
      for (int k = 0; k <= C; k++) {
        // Check if the total value of the selected coins is equal to X
        if (i * 500 + j * 100 + k * 50 == X) {
          // If yes, increment the count
          count++;
        }
      }
    }
  }

  // Return the count
  return count;
}

int main() {
  // Declare variables for the number of coins and the target value
  int A, B, C, X;

  // Read the input
  scanf("%d %d %d %d", &A, &B, &C, &X);

  // Calculate the number of ways to select coins
  int ways = count_ways(A, B, C, X);

  // Print the output
  printf("%d\n", ways);

  return 0;
}