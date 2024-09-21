#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to check if a matrix satisfies the given conditions
int check_matrix(int N, int* S, int* T, int64_t* U, int64_t* V, int64_t** a) {
  // Iterate over each row
  for (int i = 0; i < N; i++) {
    // Calculate the bitwise AND/OR of elements in the row
    int64_t row_op = S[i] == 0 ? a[i][0] : 0;
    for (int j = 1; j < N; j++) {
      if (S[i] == 0) {
        row_op &= a[i][j];
      } else {
        row_op |= a[i][j];
      }
    }
    // Check if the row operation matches the given value
    if (row_op != U[i]) {
      return 0;
    }
  }

  // Iterate over each column
  for (int j = 0; j < N; j++) {
    // Calculate the bitwise AND/OR of elements in the column
    int64_t col_op = T[j] == 0 ? a[0][j] : 0;
    for (int i = 1; i < N; i++) {
      if (T[j] == 0) {
        col_op &= a[i][j];
      } else {
        col_op |= a[i][j];
      }
    }
    // Check if the column operation matches the given value
    if (col_op != V[j]) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int N;
  scanf("%d", &N);

  // Allocate memory for the input arrays
  int* S = (int*)malloc(N * sizeof(int));
  int* T = (int*)malloc(N * sizeof(int));
  int64_t* U = (int64_t*)malloc(N * sizeof(int64_t));
  int64_t* V = (int64_t*)malloc(N * sizeof(int64_t));

  // Read the input arrays
  for (int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &T[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%lld", &U[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%lld", &V[i]);
  }

  // Allocate memory for the matrix
  int64_t** a = (int64_t**)malloc(N * sizeof(int64_t*));
  for (int i = 0; i < N; i++) {
    a[i] = (int64_t*)malloc(N * sizeof(int64_t));
  }

  // Initialize the matrix with 0s
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      a[i][j] = 0;
    }
  }

  // Try to construct a valid matrix
  int valid_matrix = 0;
  // Iterate over all possible combinations of elements in the matrix
  for (int64_t i = 0; i < (1LL << 64); i++) {
    for (int64_t j = 0; j < (1LL << 64); j++) {
      for (int64_t k = 0; k < (1LL << 64); k++) {
        for (int64_t l = 0; l < (1LL << 64); l++) {
          // Assign values to the matrix
          a[0][0] = i;
          a[0][1] = j;
          a[1][0] = k;
          a[1][1] = l;
          // Check if the matrix satisfies the conditions
          if (check_matrix(N, S, T, U, V, a)) {
            valid_matrix = 1;
            break;
          }
        }
        if (valid_matrix) {
          break;
        }
      }
      if (valid_matrix) {
        break;
      }
    }
    if (valid_matrix) {
      break;
    }
  }

  // Print the matrix or -1 if no valid matrix exists
  if (valid_matrix) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("%lld ", a[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("-1\n");
  }

  // Free allocated memory
  free(S);
  free(T);
  free(U);
  free(V);
  for (int i = 0; i < N; i++) {
    free(a[i]);
  }
  free(a);

  return 0;
}