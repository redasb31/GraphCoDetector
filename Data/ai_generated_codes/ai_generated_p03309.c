// This program calculates the minimum possible sadness of Snuke,
// given an integer sequence A of length N.
// The sadness is calculated as the sum of absolute differences
// between A_i and b+i, where b is a freely chosen integer.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Read the length of the sequence N.
  int N;
  scanf("%d", &N);

  // Allocate memory for the sequence A.
  int *A = malloc(sizeof(int) * N);

  // Read the elements of the sequence A.
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the sum of A_i.
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i];
  }

  // Calculate the sum of i.
  long long sum_i = (long long) N * (N + 1) / 2;

  // Calculate the minimum sadness by choosing b as (sum - sum_i) / N.
  long long min_sadness = abs(sum - sum_i);

  // Free the allocated memory.
  free(A);

  // Print the minimum sadness.
  printf("%lld\n", min_sadness);

  return 0;
}