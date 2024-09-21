#include <stdio.h>

int main() {
  // Declare variables for matrix dimensions
  int n, m;

  // Read matrix dimensions from the user
  scanf("%d %d", &n, &m);

  // Declare matrices and vector
  int A[100][100]; // Matrix A with maximum size 100x100
  int b[100];      // Vector b with maximum size 100
  int c[100];      // Result vector c with maximum size 100

  // Read matrix A elements
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // Read vector b elements
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }

  // Perform matrix-vector multiplication
  for (int i = 0; i < n; i++) {
    c[i] = 0; // Initialize element of c to 0
    for (int j = 0; j < m; j++) {
      c[i] += A[i][j] * b[j]; // Calculate element of c
    }
  }

  // Print result vector c
  for (int i = 0; i < n; i++) {
    printf("%d\n", c[i]);
  }

  return 0;
}