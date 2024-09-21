#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main() {
  // Input
  int N, M;
  scanf("%d %d", &N, &M);

  int *A = malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  int *B = malloc(M * sizeof(int));
  int *C = malloc(M * sizeof(int));
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &B[i], &C[i]);
  }

  // Sort the cards in ascending order
  qsort(A, N, sizeof(int), cmp);

  // Perform the operations in reverse order
  long long sum = 0; // Use long long to handle potential overflow
  for (int i = M - 1; i >= 0; i--) {
    // Replace the B_i smallest cards with C_i
    for (int j = 0; j < B[i]; j++) {
      if (A[j] < C[i]) {
        A[j] = C[i];
      }
    }
  }

  // Calculate the sum
  for (int i = 0; i < N; i++) {
    sum += A[i];
  }

  printf("%lld\n", sum);

  free(A);
  free(B);
  free(C);

  return 0;
}