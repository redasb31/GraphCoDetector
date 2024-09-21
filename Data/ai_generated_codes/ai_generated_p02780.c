#include <stdio.h>
#include <stdlib.h>

int main() {
  // Read input
  int N, K;
  scanf("%d %d", &N, &K);
  int *p = malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &p[i]);
  }

  // Calculate the expected value of each die
  double *expected_values = malloc(sizeof(double) * N);
  for (int i = 0; i < N; i++) {
    expected_values[i] = (double)(p[i] + 1) / 2; // Expected value is (p + 1)/2
  }

  // Find the maximum sum of expected values for K adjacent dice
  double max_sum = 0;
  for (int i = 0; i <= N - K; i++) {
    double sum = 0;
    for (int j = i; j < i + K; j++) {
      sum += expected_values[j];
    }
    if (sum > max_sum) {
      max_sum = sum;
    }
  }

  // Print the maximum expected value
  printf("%.12lf\n", max_sum);

  // Free allocated memory
  free(p);
  free(expected_values);

  return 0;
}