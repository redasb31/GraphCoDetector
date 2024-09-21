#include <stdio.h>
#include <stdlib.h>

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int N, X;
  // Read the number of cities (N) and the starting coordinate (X)
  scanf("%d %d", &N, &X);

  // Allocate memory for the city coordinates
  int *cities = (int *)malloc(sizeof(int) * N);

  // Read the city coordinates
  for (int i = 0; i < N; i++) {
    scanf("%d", &cities[i]);
  }

  // Calculate the differences between each city coordinate and the starting coordinate
  int *diffs = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    diffs[i] = abs(cities[i] - X);
  }

  // Find the greatest common divisor (GCD) of all the differences
  int max_D = diffs[0];
  for (int i = 1; i < N; i++) {
    max_D = gcd(max_D, diffs[i]);
  }

  // Print the maximum value of D
  printf("%d\n", max_D);

  // Free the allocated memory
  free(cities);
  free(diffs);

  return 0;
}