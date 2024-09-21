#include <stdio.h>
#include <string.h>

int main() {
  // N: size of the matrix
  int N;
  scanf("%d", &N);

  // matrix: 2D array to store the characters from the input
  char matrix[50][50];

  // Read the characters from the input
  for (int i = 0; i < N; i++) {
    scanf("%s", matrix[i]);
  }

  // message: string to store the decoded message
  char message[50];

  // Initialize the message string with null characters
  memset(message, '\0', sizeof(message));

  // visited: 2D array to keep track of visited characters
  int visited[50][50] = {0};

  // row: current row index
  int row = 0;

  // col: current column index
  int col = 0;

  // i: loop counter for selecting characters
  int i = 0;

  // Select characters from the matrix
  while (i < N) {
    // Find the lexicographically smallest character in the current row
    char minChar = matrix[row][col];
    int minRow = row;
    int minCol = col;
    for (int j = 0; j < N; j++) {
      if (!visited[row][j] && matrix[row][j] < minChar) {
        minChar = matrix[row][j];
        minRow = row;
        minCol = j;
      }
    }

    // Add the lexicographically smallest character to the message
    message[i] = minChar;

    // Mark the character as visited
    visited[minRow][minCol] = 1;

    // Move to the next row and column
    row = (row + 1) % N;
    col = (col + 1) % N;

    // Increment the counter
    i++;
  }

  // Print the decoded message
  printf("%s\n", message);

  return 0;
}