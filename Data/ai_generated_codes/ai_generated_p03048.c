#include <stdio.h>

int main() {
  // Declare variables to store the number of balls in each box and the total number of balls needed
  int R, G, B, N;

  // Read the input values
  scanf("%d %d %d %d", &R, &G, &B, &N);

  // Initialize a counter to store the number of possible combinations
  int count = 0;

  // Iterate through all possible values of red boxes (r)
  for (int r = 0; r * R <= N; r++) {
    // Iterate through all possible values of green boxes (g)
    for (int g = 0; r * R + g * G <= N; g++) {
      // Calculate the number of blue boxes (b) required
      int b = (N - r * R - g * G) / B;
      // If the number of blue boxes is non-negative and the total number of balls matches the requirement, increment the counter
      if (b >= 0 && r * R + g * G + b * B == N) {
        count++;
      }
    }
  }

  // Print the number of possible combinations
  printf("%d\n", count);

  return 0;
}