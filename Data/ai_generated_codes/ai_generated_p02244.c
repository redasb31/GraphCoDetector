#include <stdio.h>
#include <stdbool.h>

#define N 8

// Function to check if a position is under attack by any other queen
bool is_attacked(int board[][N], int row, int col) {
  // Check row and column
  for (int i = 0; i < N; i++) {
    if (board[row][i] == 'Q' || board[i][col] == 'Q') {
      return true;
    }
  }

  // Check diagonals
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 'Q' && (abs(row - i) == abs(col - j))) {
        return true;
      }
    }
  }

  return false;
}

// Function to solve the 8 queens problem using backtracking
bool solve_queens(int board[][N], int col) {
  // Base case: all queens are placed
  if (col == N) {
    return true;
  }

  // Try placing a queen in each row of the current column
  for (int row = 0; row < N; row++) {
    // If the position is not under attack
    if (!is_attacked(board, row, col)) {
      // Place the queen
      board[row][col] = 'Q';

      // Recursively solve for the next column
      if (solve_queens(board, col + 1)) {
        return true;
      }

      // If placing the queen in the current position didn't lead to a solution,
      // backtrack by removing the queen
      board[row][col] = '.';
    }
  }

  // No solution found in this column
  return false;
}

int main() {
  int k;
  scanf("%d", &k);

  // Initialize the chess board
  int board[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = '.';
    }
  }

  // Place the pre-existing queens
  int row, col;
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &row, &col);
    board[row][col] = 'Q';
  }

  // Solve the 8 queens problem
  if (solve_queens(board, 0)) {
    // Print the solution
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("%c", board[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("No solution found.\n");
  }

  return 0;
}