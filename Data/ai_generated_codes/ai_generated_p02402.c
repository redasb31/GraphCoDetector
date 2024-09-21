#include <stdio.h>
#include <limits.h>

int main() {
  // Declare variables to store the number of integers, the current integer, the minimum, maximum, and sum.
  int n, i, current, min = INT_MAX, max = INT_MIN, sum = 0;

  // Read the number of integers from the user.
  scanf("%d", &n);

  // Loop through each integer in the sequence.
  for (i = 0; i < n; i++) {
    // Read the current integer from the user.
    scanf("%d", &current);

    // Update the minimum and maximum values if necessary.
    if (current < min) {
      min = current;
    }
    if (current > max) {
      max = current;
    }

    // Add the current integer to the sum.
    sum += current;
  }

  // Print the minimum, maximum, and sum.
  printf("%d %d %d\n", min, max, sum);

  return 0;
}