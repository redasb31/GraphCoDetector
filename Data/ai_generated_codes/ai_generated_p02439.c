#include <stdio.h>

int main() {
  // Declare variables to store the three integers.
  int a, b, c;

  // Read the three integers from the input.
  scanf("%d %d %d", &a, &b, &c);

  // Find the minimum value using a nested if-else statement.
  int min = a;
  if (b < min) {
    min = b;
  }
  if (c < min) {
    min = c;
  }

  // Find the maximum value using a nested if-else statement.
  int max = a;
  if (b > max) {
    max = b;
  }
  if (c > max) {
    max = c;
  }

  // Print the minimum and maximum values separated by a space.
  printf("%d %d\n", min, max);

  return 0;
}