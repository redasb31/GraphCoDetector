#include <stdio.h>

int main() {
  // Declare variables to store the input values
  int S, T, D;
  int i, weight, days = 0;

  // Read the input values
  scanf("%d %d %d", &S, &T, &D);

  // Declare an array to store the weight changes for each day
  int w[D];
  for (i = 0; i < D; i++) {
    scanf("%d", &w[i]);
  }

  // Simulate Chokudai's slimming plan
  weight = S; // Initial weight
  while (weight > T) {
    // Calculate the weight change for the current day
    weight += w[days % D];
    days++;
  }

  // Print the result
  if (weight <= T) {
    printf("%d\n", days); // Chokudai's plan ended successfully
  } else {
    printf("-1\n"); // Chokudai's plan never ends
  }

  return 0;
}