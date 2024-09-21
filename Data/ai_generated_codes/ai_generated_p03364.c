#include <stdio.h>
#include <string.h>

int main() {
  int N;
  scanf("%d", &N);

  // Store the first board as a 2D character array
  char board[300][300];
  for (int i = 0; i < N; i++) {
    scanf("%s", board[i]);
  }

  // Initialize a counter for good boards
  int count = 0;

  // Iterate through all possible values of A and B
  for (int A = 0; A < N; A++) {
    for (int B = 0; B < N; B++) {
      // Check if the second board is good for this A and B
      int is_good = 1;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          // Calculate the indices for the corresponding square in the first board
          int x = (i + A) % N;
          int y = (j + B) % N;

          // Compare the letters in the corresponding squares
          if (board[i][j] != board[j][i]) {
            is_good = 0;
            break;
          }
        }
        if (!is_good) {
          break;
        }
      }

      // Increment the counter if the board is good
      if (is_good) {
        count++;
      }
    }
  }

  // Print the final count of good boards
  printf("%d\n", count);

  return 0;
}