#include <stdio.h>

int main() {
  // Declare variables for the three integers and the number of operations
  int A, B, C, K;

  // Read the input values
  scanf("%d %d %d", &A, &B, &C);
  scanf("%d", &K);

  // Initialize the maximum sum to the initial sum
  int max_sum = A + B + C;

  // Iterate through the possible operations
  for (int i = 0; i < K; i++) {
    // Calculate the sum after doubling each of the integers
    int sum1 = 2 * A + B + C;
    int sum2 = A + 2 * B + C;
    int sum3 = A + B + 2 * C;

    // Update the maximum sum if necessary
    max_sum = (sum1 > max_sum) ? sum1 : max_sum;
    max_sum = (sum2 > max_sum) ? sum2 : max_sum;
    max_sum = (sum3 > max_sum) ? sum3 : max_sum;
  }

  // Print the maximum sum
  printf("%d\n", max_sum);

  return 0;
}