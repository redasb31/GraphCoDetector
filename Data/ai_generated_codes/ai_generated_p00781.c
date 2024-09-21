#include <stdio.h>
#include <string.h>

// Function to check if two boards are compatible
int compatible(char *board1, char *board2) {
  // Check if the shallow slits of one board match the deep slits of the other
  for (int i = 0; i < 5; i++) {
    if (board1[i] == '1' && board2[i] == '0' ||
        board1[i] == '0' && board2[i] == '1') {
      return 1;
    }
  }
  return 0;
}

// Function to check if a board can be placed in a row or column
int check_placement(char *board, char *lattice[4][4], int row, int col, int orientation) {
  // Check if the board is compatible with the adjacent boards
  if (orientation == 0) { // Horizontal
    if (row > 0 && !compatible(board, lattice[row - 1][col])) {
      return 0;
    }
    if (row < 3 && !compatible(board, lattice[row + 1][col])) {
      return 0;
    }
    if (col > 0 && !compatible(board, lattice[row][col - 1])) {
      return 0;
    }
    if (col < 3 && !compatible(board, lattice[row][col + 1])) {
      return 0;
    }
  } else { // Vertical
    if (col > 0 && !compatible(board, lattice[row][col - 1])) {
      return 0;
    }
    if (col < 3 && !compatible(board, lattice[row][col + 1])) {
      return 0;
    }
    if (row > 0 && !compatible(board, lattice[row - 1][col])) {
      return 0;
    }
    if (row < 3 && !compatible(board, lattice[row + 1][col])) {
      return 0;
    }
  }
  return 1;
}

// Recursive function to count the number of possible configurations
int count_configurations(char *boards[10], char *lattice[4][4], int index, int used) {
  if (index == 10) {
    return 1;
  }
  int count = 0;
  // Try placing each board in all possible positions
  for (int i = 0; i < 10; i++) {
    if ((used >> i) & 1) {
      continue;
    }
    for (int row = 0; row < 4; row++) {
      for (int col = 0; col < 4; col++) {
        // Check if the board can be placed in the current position
        if (lattice[row][col][0] == '\0') {
          for (int orientation = 0; orientation < 2; orientation++) {
            if (check_placement(boards[i], lattice, row, col, orientation)) {
              // Place the board in the lattice
              if (orientation == 0) {
                strcpy(lattice[row][col], boards[i]);
              } else {
                strcpy(lattice[row][col], boards[i]);
                // Rotate the board for vertical placement
                for (int j = 0; j < 3; j++) {
                  char temp = lattice[row][col][j];
                  lattice[row][col][j] = lattice[row][col][4 - j];
                  lattice[row][col][4 - j] = temp;
                }
              }
              // Recursively count the configurations for the remaining boards
              count += count_configurations(boards, lattice, index + 1, used | (1 << i));
              // Remove the board from the lattice
              lattice[row][col][0] = '\0';
            }
          }
        }
      }
    }
  }
  return count;
}

int main() {
  char input[100];
  char boards[10][6];
  char lattice[4][4][6];

  // Initialize the lattice
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      lattice[i][j][0] = '\0';
    }
  }

  while (1) {
    scanf("%s", input);
    if (strcmp(input, "END") == 0) {
      break;
    }

    // Parse the input string
    int k = 0;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 5; j++) {
        boards[i][j] = input[k++];
      }
      boards[i][5] = '\0';
    }

    // Count the number of possible configurations
    int count = count_configurations(boards, lattice, 0, 0);
    printf("%d\n", count);
  }
  return 0;
}