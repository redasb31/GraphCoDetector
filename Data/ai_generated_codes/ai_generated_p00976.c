#include <stdio.h>

// Function to calculate the rank of a matrix
int rank(int A[][1000], int n, int m) {
  int rank = 0, i, j, k;
  for (i = 0; i < n; i++) {
    for (j = rank; j < m; j++) {
      if (A[i][j]) {
        // Swap rows i and rank to bring the non-zero element to the leading position
        for (k = 0; k < m; k++) {
          int temp = A[i][k];
          A[i][k] = A[rank][k];
          A[rank][k] = temp;
        }
        // Perform Gaussian elimination to make all elements below the leading element 0
        for (k = i + 1; k < n; k++) {
          if (A[k][j]) {
            for (int l = 0; l < m; l++) {
              A[k][l] ^= A[rank][l];
            }
          }
        }
        rank++;
        break;
      }
    }
  }
  return rank;
}

int main() {
  int n, m, i, j, A[1000][1000], r, r_ij;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%1d", &A[i][j]);
    }
  }

  // Calculate the rank of the original matrix
  r = rank(A, n, m);

  // Iterate through all entries of the matrix and calculate the rank after flipping
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      // Flip the entry
      A[i][j] ^= 1;
      // Calculate the rank of the modified matrix
      r_ij = rank(A, n, m);
      // Print the result based on the change in rank
      if (r_ij < r) {
        printf("-");
      } else if (r_ij == r) {
        printf("0");
      } else {
        printf("+");
      }
      // Revert the entry back to its original value
      A[i][j] ^= 1;
    }
    printf("\n");
  }
  return 0;
}