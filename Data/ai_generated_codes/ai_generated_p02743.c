#include <stdio.h>
#include <math.h>

int main() {
  // Declare variables to store the input values
  int a, b, c;

  // Read the input values from the user
  scanf("%d %d %d", &a, &b, &c);

  // Calculate the square roots of a, b, and c
  double sqrt_a = sqrt(a);
  double sqrt_b = sqrt(b);
  double sqrt_c = sqrt(c);

  // Check if the inequality holds
  if (sqrt_a + sqrt_b < sqrt_c) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}