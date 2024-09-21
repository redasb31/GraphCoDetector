#include <stdio.h>

int main() {
  // Declare variables to store the input values
  int T, X;

  // Read the input values from the user
  scanf("%d %d", &T, &X);

  // Calculate the time that will pass in World A
  double time_in_world_a = (double)T / X;

  // Print the result with the required precision
  printf("%.12lf\n", time_in_world_a);

  return 0;
}