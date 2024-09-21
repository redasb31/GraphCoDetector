#include <stdio.h>
#include <stdlib.h>

int main() {
  // N: the length of the sequences
  int N;
  scanf("%d", &N);

  // A: the first sequence
  int *A = malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // B: the second sequence
  int *B = malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
  }

  // Check if the objective is achievable
  int count = 0; // Count the number of swaps
  for (int i = 0; i < N; i++) {
    // If A[i] > B[i], we need to swap A[i] with a smaller value
    if (A[i] > B[i]) {
      // Find a smaller value in A
      int j;
      for (j = i + 1; j < N; j++) {
        if (A[j] < B[i]) {
          break;
        }
      }

      // If a smaller value is found, swap them
      if (j < N) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        count++;
      } else {
        // If no smaller value is found, the objective is not achievable
        free(A);
        free(B);
        printf("No\n");
        return 0;
      }
    }
  }

  // If the number of swaps is less than or equal to N-2, the objective is achievable
  if (count <= N - 2) {
    free(A);
    free(B);
    printf("Yes\n");
  } else {
    free(A);
    free(B);
    printf("No\n");
  }

  return 0;
}