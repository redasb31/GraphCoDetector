#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input the number of examinations
  int N;
  scanf("%d", &N);

  // Input the readiness for each examination
  int *A = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Input the required readiness for each examination
  int *B = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
  }

  // Calculate the total readiness
  long long int total_readiness = 0;
  for (int i = 0; i < N; i++) {
    total_readiness += A[i];
  }

  // Check if it is possible to pass all examinations
  long long int required_readiness = 0;
  for (int i = 0; i < N; i++) {
    required_readiness += B[i];
  }
  if (total_readiness < required_readiness) {
    printf("-1\n");
    free(A);
    free(B);
    return 0;
  }

  // Calculate the minimum number of changes
  int changes = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] < B[i]) {
      changes++;
    }
  }

  // Print the minimum number of changes
  printf("%d\n", changes);

  // Free the allocated memory
  free(A);
  free(B);

  return 0;
}