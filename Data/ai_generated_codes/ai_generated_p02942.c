#include <stdio.h>

int main() {
  // Read the input
  int N, M;
  scanf("%d %d", &N, &M);
  int A[N][M];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // Step 1: Rearrange rows
  int B[N][M];
  for (int i = 0; i < N; i++) {
    // Sort each row in ascending order
    for (int j = 0; j < M; j++) {
      for (int k = j + 1; k < M; k++) {
        if (A[i][j] > A[i][k]) {
          int temp = A[i][j];
          A[i][j] = A[i][k];
          A[i][k] = temp;
        }
      }
      B[i][j] = A[i][j];
    }
  }

  // Step 2: Rearrange columns
  int C[N][M];
  for (int j = 0; j < M; j++) {
    // Sort each column in ascending order
    for (int i = 0; i < N; i++) {
      for (int k = i + 1; k < N; k++) {
        if (B[i][j] > B[k][j]) {
          int temp = B[i][j];
          B[i][j] = B[k][j];
          B[k][j] = temp;
        }
      }
      C[i][j] = B[i][j];
    }
  }

  // Step 3: Rearrange rows again
  for (int i = 0; i < N; i++) {
    // Reverse each row
    for (int j = 0; j < M / 2; j++) {
      int temp = C[i][j];
      C[i][j] = C[i][M - j - 1];
      C[i][M - j - 1] = temp;
    }
  }

  // Print the output
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}