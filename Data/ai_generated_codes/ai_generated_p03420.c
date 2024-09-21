#include <stdio.h>

int main() {
  // Declare variables to store input values
  int N, K;

  // Read input values from standard input
  scanf("%d %d", &N, &K);

  // Initialize a variable to store the count of possible pairs
  long long count = 0;

  // Iterate through all possible values of 'a'
  for (int a = 1; a <= N; a++) {
    // Iterate through all possible values of 'b' less than 'a'
    for (int b = 1; b < a; b++) {
      // Check if the remainder of 'a' divided by 'b' is greater than or equal to 'K'
      if (a % b >= K) {
        // Increment the count if the condition is met
        count++;
      }
    }
  }

  // Print the count of possible pairs
  printf("%lld\n", count);

  return 0;
}