#include <stdio.h>

#define MAX_N 100000
#define MAX_H 100000
#define MAX_W 100000

int main() {
  int N, H, W;
  int R[MAX_N], C[MAX_N], A[MAX_N];
  int row_max[MAX_H] = {0}; // Array to store the maximum value for each row
  int col_max[MAX_W] = {0}; // Array to store the maximum value for each column
  int i, j, max_sum = 0;

  // Input the number of cards, number of rows, and number of columns
  scanf("%d %d %d", &N, &H, &W);

  // Input the row, column, and value of each card
  for (i = 0; i < N; i++) {
    scanf("%d %d %d", &R[i], &C[i], &A[i]);

    // Update the maximum value for the corresponding row and column
    row_max[R[i] - 1] = (row_max[R[i] - 1] < A[i]) ? A[i] : row_max[R[i] - 1];
    col_max[C[i] - 1] = (col_max[C[i] - 1] < A[i]) ? A[i] : col_max[C[i] - 1];
  }

  // Calculate the maximum sum by iterating through the rows and columns
  for (i = 0; i < H; i++) {
    max_sum += row_max[i];
  }
  for (j = 0; j < W; j++) {
    max_sum += col_max[j];
  }

  // Print the maximum possible sum
  printf("%d\n", max_sum);

  return 0;
}