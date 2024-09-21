#include <stdio.h>

int main() {
  // Declare variables to store input values
  int N, K;

  // Read input values from the user
  scanf("%d %d", &N, &K);

  // Initialize a counter for the number of possible pairs
  int count = 0;

  // Iterate through all possible values of a (1 to N)
  for (int a = 1; a <= N; a++) {
    // Iterate through all possible values of b (1 to a-1)
    for (int b = 1; b <= a - 1; b++) {
      // Check if the remainder of a divided by b is greater than or equal to K
      if (a % b >= K) {
        // Increment the counter if the condition is met
        count++;
      }
    }
  }

  // Print the total number of possible pairs
  printf("%d\n", count);

  return 0;
}