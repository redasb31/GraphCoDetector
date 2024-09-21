#include <stdio.h>

int main() {
  // Declare variables to store the bingo card and the called numbers
  int bingo_card[3][3];
  int n; // Number of called numbers
  int called_numbers[10]; 

  // Read the bingo card from input
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &bingo_card[i][j]);
    }
  }

  // Read the number of called numbers and the called numbers themselves
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &called_numbers[i]);
  }

  // Initialize variables to track if there is a bingo
  int bingo = 0;
  int row_count[3] = {0, 0, 0}; // Count of marked numbers in each row
  int col_count[3] = {0, 0, 0}; // Count of marked numbers in each column
  int diag1_count = 0; // Count of marked numbers in the top-left to bottom-right diagonal
  int diag2_count = 0; // Count of marked numbers in the top-right to bottom-left diagonal

  // Check each called number against the bingo card
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        // If a called number matches a number on the bingo card
        if (called_numbers[i] == bingo_card[j][k]) {
          // Increment the counts for the corresponding row, column, and diagonals
          row_count[j]++;
          col_count[k]++;
          if (j == k) {
            diag1_count++;
          }
          if (j + k == 2) {
            diag2_count++;
          }
          // Check if there is a bingo
          if (row_count[j] == 3 || col_count[k] == 3 || diag1_count == 3 || diag2_count == 3) {
            bingo = 1;
          }
        }
      }
    }
  }

  // Print the result
  if (bingo) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}