#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  int N, M; // N: number of guests, M: number of handshakes
  scanf("%d %d", &N, &M);

  // Array to store the power of each guest
  int *A = (int *)malloc(N * sizeof(int));

  // Input the power of each guest
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Sort the array in descending order
  qsort(A, N, sizeof(int), compare);

  // Calculate the maximum happiness
  long long happiness = 0;
  for (int i = 0; i < M; i++) {
    happiness += A[i] + A[N - i - 1];
  }

  // Print the maximum happiness
  printf("%lld\n", happiness);

  // Free the allocated memory
  free(A);
  return 0;
}