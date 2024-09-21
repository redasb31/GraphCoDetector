#include <stdio.h>

int main() {
  // Declare a variable to store the number of sides of the polygon
  int N;

  // Read the number of sides from the standard input
  scanf("%d", &N);

  // Calculate the sum of the interior angles using the formula: (N - 2) * 180
  int sum = (N - 2) * 180;

  // Print the sum of the interior angles
  printf("%d\n", sum);

  return 0;
}