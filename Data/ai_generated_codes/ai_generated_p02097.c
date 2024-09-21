#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  // Check if N is odd
  if (N % 2 == 1) {
    printf("No\n");
    return 0;
  }

  // Create a matrix of size N x N
  int matrix[N][N];

  // Fill the matrix
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // For even rows, fill with ascending numbers
      if (i % 2 == 0) {
        matrix[i][j] = j + 1 + i;
      }
      // For odd rows, fill with descending numbers
      else {
        matrix[i][j] = N + i - j;
      }
      // Ensure values are within the range [1, 2N - 1]
      matrix[i][j] = matrix[i][j] % (2 * N - 1);
      if (matrix[i][j] == 0) {
        matrix[i][j] = 2 * N - 1;
      }
    }
  }

  // Print the matrix
  printf("Yes\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}