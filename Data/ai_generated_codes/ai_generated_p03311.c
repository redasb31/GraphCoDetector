#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // N: the length of the sequence
  int N;
  // Read the length of the sequence
  scanf("%d", &N);

  // Allocate memory for the sequence
  int *A = malloc(sizeof(int) * N);

  // Read the sequence
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the sum of the elements of the sequence
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i];
  }

  // Calculate the sum of the indices of the sequence
  long long index_sum = (long long) N * (N + 1) / 2;

  // Calculate the optimal value of b
  long long b = (sum - index_sum) / N;

  // Calculate the minimum possible sadness
  long long min_sadness = 0;
  for (int i = 0; i < N; i++) {
    min_sadness += abs(A[i] - (b + i + 1));
  }

  // Print the minimum possible sadness
  printf("%lld\n", min_sadness);

  // Free the allocated memory
  free(A);

  return 0;
}