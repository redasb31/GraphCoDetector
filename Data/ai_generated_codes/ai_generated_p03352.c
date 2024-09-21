#include <stdio.h>
#include <math.h>

int main() {
  // Read the input integer X.
  int X;
  scanf("%d", &X);

  // Initialize the largest perfect power found so far.
  int largest_perfect_power = 1;

  // Iterate through all possible bases b.
  for (int b = 2; b <= X; b++) {
    // Iterate through all possible exponents p.
    for (int p = 2; pow(b, p) <= X; p++) {
      // Update the largest perfect power if necessary.
      if (pow(b, p) > largest_perfect_power) {
        largest_perfect_power = pow(b, p);
      }
    }
  }

  // Print the largest perfect power.
  printf("%d\n", largest_perfect_power);

  return 0;
}