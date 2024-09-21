#include <stdio.h>

int main() {
  // N: Number of codes
  // M: Number of characteristics
  int N, M, C, i, j, count = 0;
  // B: Array of coefficients
  int B[20];
  // A: 2D array of code characteristics
  int A[20][20];

  // Read input values
  scanf("%d %d %d", &N, &M, &C);
  for (i = 0; i < M; i++) {
    scanf("%d", &B[i]);
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // Check each code for correctness
  for (i = 0; i < N; i++) {
    int sum = C;
    for (j = 0; j < M; j++) {
      sum += A[i][j] * B[j];
    }
    // If the sum is greater than 0, the code is correct
    if (sum > 0) {
      count++;
    }
  }

  // Print the number of correct codes
  printf("%d\n", count);

  return 0;
}