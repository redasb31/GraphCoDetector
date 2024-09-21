#include <stdio.h>

int main() {
  int r, c; // Number of rows and columns
  scanf("%d %d", &r, &c); // Read rows and columns

  int table[r][c]; // 2D array to store the table
  int row_sum[r]; // Array to store sum of each row
  int col_sum[c]; // Array to store sum of each column
  int total_sum = 0; // Variable to store the total sum

  // Read the table elements
  for (int i = 0; i < r; i++) {
    row_sum[i] = 0; // Initialize row sum to 0
    for (int j = 0; j < c; j++) {
      scanf("%d", &table[i][j]);
      row_sum[i] += table[i][j]; // Calculate row sum
      total_sum += table[i][j]; // Calculate total sum
    }
  }

  // Calculate column sum
  for (int j = 0; j < c; j++) {
    col_sum[j] = 0; // Initialize column sum to 0
    for (int i = 0; i < r; i++) {
      col_sum[j] += table[i][j]; // Calculate column sum
    }
  }

  // Print the table with row and column sums
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d ", table[i][j]); // Print table element
    }
    printf("%d ", row_sum[i]); // Print row sum
    printf("\n"); // Newline after each row
  }

  // Print the column sums in the last row
  for (int j = 0; j < c; j++) {
    printf("%d ", col_sum[j]); // Print column sum
  }
  printf("%d\n", total_sum); // Print total sum

  return 0;
}