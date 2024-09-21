#include <stdio.h>

int main() {
  int n, i, j;
  int table[100][100]; // Assuming maximum size of table to be 100x100
  int rowSum[100]; // Array to store row sums
  int colSum[100]; // Array to store column sums

  while (1) {
    scanf("%d", &n);
    if (n == 0) { // Exit condition
      break;
    }

    // Read the table input
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &table[i][j]);
      }
    }

    // Calculate row sums
    for (i = 0; i < n; i++) {
      rowSum[i] = 0;
      for (j = 0; j < n; j++) {
        rowSum[i] += table[i][j];
      }
    }

    // Calculate column sums
    for (j = 0; j < n; j++) {
      colSum[j] = 0;
      for (i = 0; i < n; i++) {
        colSum[j] += table[i][j];
      }
    }

    // Print the table with row and column sums
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf("%5d", table[i][j]); // Print each element with a margin of 5 digits
      }
      printf("%5d\n", rowSum[i]); // Print row sum at the end of each row
    }
    for (j = 0; j < n; j++) {
      printf("%5d", colSum[j]); // Print column sums at the end of the table
    }
    printf("%5d\n", 0); // Print final 0 to align the output correctly
  }

  return 0;
}