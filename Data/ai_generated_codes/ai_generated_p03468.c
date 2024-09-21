#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the probability of coverage
double calculateProbability(int N, int C, int *L) {
  // Calculate the total length of the arcs
  int totalLength = 0;
  for (int i = 0; i < N; i++) {
    totalLength += L[i];
  }

  // If the total length of the arcs is less than the circle's length, the probability is 0
  if (totalLength < C) {
    return 0.0;
  }

  // If the total length of the arcs is exactly equal to the circle's length, the probability is 0
  if (totalLength == C) {
    return 0.0;
  }

  // Calculate the probability of each arc covering a point on the circle
  double probability = 1.0;
  for (int i = 0; i < N; i++) {
    probability *= (double)L[i] / C;
  }

  // Return the final probability
  return probability;
}

int main() {
  // Read the input
  int N, C;
  scanf("%d %d", &N, &C);

  // Allocate memory for the arc lengths
  int *L = malloc(N * sizeof(int));

  // Read the arc lengths
  for (int i = 0; i < N; i++) {
    scanf("%d", &L[i]);
  }

  // Calculate the probability and print the result
  double result = calculateProbability(N, C, L);
  printf("%.16lf\n", result);

  // Free the allocated memory
  free(L);

  return 0;
}