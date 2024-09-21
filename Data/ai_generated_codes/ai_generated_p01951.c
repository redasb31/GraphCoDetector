#include <stdio.h>
#include <stdlib.h>

// Function to check if there exists a horizontal contiguous subsequence with sum greater than S
int check_horizontal(int **matrix, int n, int m, int s) {
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      sum += matrix[i][j];
      if (sum > s) {
        return 1;
      }
    }
  }
  return 0;
}

// Function to check if there exists a vertical contiguous subsequence with sum greater than S
int check_vertical(int **matrix, int n, int m, int s) {
  for (int j = 0; j < m; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += matrix[i][j];
      if (sum > s) {
        return 1;
      }
    }
  }
  return 0;
}

// Function to determine if you can exchange the card for a prize
int can_exchange(int **matrix, int n, int m, int k, int s) {
  // Check if the matrix already satisfies the condition
  if (!check_horizontal(matrix, n, m, s) && !check_vertical(matrix, n, m, s)) {
    return 1;
  }

  // Try flipping the sign of each element and check if the condition is satisfied
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] *= -1;
      if (!check_horizontal(matrix, n, m, s) && !check_vertical(matrix, n, m, s)) {
        return 1;
      }
      matrix[i][j] *= -1;
    }
  }

  return 0;
}

int main() {
  int n, m, k, s;
  scanf("%d %d %d %d", &n, &m, &k, &s);

  // Allocate memory for the matrix
  int **matrix = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    matrix[i] = (int *)malloc(m * sizeof(int));
  }

  // Read the matrix elements
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  // Determine if you can exchange the card for a prize
  if (can_exchange(matrix, n, m, k, s)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  // Free the allocated memory
  for (int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}