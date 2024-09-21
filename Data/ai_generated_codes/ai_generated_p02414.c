#include <stdio.h>

int main() {
  // Declare variables for matrix dimensions
  int n, m, l;

  // Read matrix dimensions from input
  scanf("%d %d %d", &n, &m, &l);

  // Declare matrices A, B, and C
  int A[n][m], B[m][l], C[n][l];

  // Read matrix A from input
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // Read matrix B from input
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < l; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  // Calculate matrix C (product of A and B)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l; j++) {
      C[i][j] = 0; // Initialize element of C to 0
      for (int k = 0; k < m; k++) {
        // Calculate element of C using the formula
        C[i][j] += A[i][k] * B[k][j]; 
      }
    }
  }

  // Print matrix C
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n"); // Print newline after each row
  }

  return 0;
}