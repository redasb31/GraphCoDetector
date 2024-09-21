#include <stdio.h>
#include <string.h>

// Define the possible edge symbols
#define SYMBOLS "RGBWrgbw"

// Define the number of pieces in a puzzle
#define NUM_PIECES 9

// Define the size of the puzzle grid
#define GRID_SIZE 3

// Function to check if two pieces are rotationally equal
int is_rotationally_equal(char *piece1, char *piece2) {
  // Rotate piece1 and compare with piece2
  for (int i = 0; i < 4; i++) {
    if (strcmp(piece1, piece2) == 0) {
      return 1;
    }
    // Rotate piece1 by 90 degrees
    char temp = piece1[0];
    piece1[0] = piece1[3];
    piece1[3] = piece1[2];
    piece1[2] = piece1[1];
    piece1[1] = temp;
  }
  return 0;
}

// Function to check if a piece is rotationally symmetric
int is_rotationally_symmetric(char *piece) {
  // Check if the piece is equal to its 180 degree rotation
  char rotated_piece[5];
  strcpy(rotated_piece, piece);
  rotated_piece[0] = piece[2];
  rotated_piece[2] = piece[0];
  rotated_piece[1] = piece[3];
  rotated_piece[3] = piece[1];
  return strcmp(piece, rotated_piece) == 0;
}

// Function to check if a piece can be placed at a given position in the grid
int can_place_piece(char *piece, char grid[GRID_SIZE][GRID_SIZE], int row, int col) {
  // Check if the piece can be placed on the top edge
  if (row > 0 && grid[row - 1][col][2] != piece[0]) {
    return 0;
  }
  // Check if the piece can be placed on the right edge
  if (col < GRID_SIZE - 1 && grid[row][col + 1][3] != piece[1]) {
    return 0;
  }
  // Check if the piece can be placed on the bottom edge
  if (row < GRID_SIZE - 1 && grid[row + 1][col][0] != piece[2]) {
    return 0;
  }
  // Check if the piece can be placed on the left edge
  if (col > 0 && grid[row][col - 1][1] != piece[3]) {
    return 0;
  }
  return 1;
}

// Function to recursively solve the puzzle
int solve_puzzle(char *pieces[], char grid[GRID_SIZE][GRID_SIZE], int piece_index) {
  // Base case: all pieces have been placed
  if (piece_index == NUM_PIECES) {
    return 1;
  }

  // Try placing each remaining piece at every possible position
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int col = 0; col < GRID_SIZE; col++) {
      // Check if the piece can be placed at the current position
      if (can_place_piece(pieces[piece_index], grid, row, col)) {
        // Place the piece at the current position
        strcpy(grid[row][col], pieces[piece_index]);

        // Recursively solve the puzzle with the remaining pieces
        int solutions = solve_puzzle(pieces, grid, piece_index + 1);

        // If a solution is found, return the number of solutions
        if (solutions > 0) {
          return solutions;
        }

        // Otherwise, remove the piece from the current position
        strcpy(grid[row][col], "");
      }
    }
  }

  // No solution found
  return 0;
}

int main() {
  int num_puzzles;
  scanf("%d", &num_puzzles);

  // Loop through each puzzle
  for (int i = 0; i < num_puzzles; i++) {
    // Read the puzzle pieces
    char pieces[NUM_PIECES][5];
    char input_line[50];
    scanf("%s", input_line);
    char *piece = strtok(input_line, " ");
    for (int j = 0; j < NUM_PIECES; j++) {
      strcpy(pieces[j], piece);
      piece = strtok(NULL, " ");
    }

    // Check for invalid puzzle conditions
    // 1. Identical pieces
    for (int j = 0; j < NUM_PIECES; j++) {
      for (int k = j + 1; k < NUM_PIECES; k++) {
        if (strcmp(pieces[j], pieces[k]) == 0) {
          printf("0\n");
          goto next_puzzle;
        }
      }
    }
    // 2. Rotationally equal pieces
    for (int j = 0; j < NUM_PIECES; j++) {
      for (int k = j + 1; k < NUM_PIECES; k++) {
        if (is_rotationally_equal(pieces[j], pieces[k])) {
          printf("0\n");
          goto next_puzzle;
        }
      }
    }
    // 3. Rotationally symmetric pieces
    for (int j = 0; j < NUM_PIECES; j++) {
      if (is_rotationally_symmetric(pieces[j])) {
        printf("0\n");
        goto next_puzzle;
      }
    }

    // Initialize the puzzle grid
    char grid[GRID_SIZE][GRID_SIZE][5];
    for (int j = 0; j < GRID_SIZE; j++) {
      for (int k = 0; k < GRID_SIZE; k++) {
        strcpy(grid[j][k], "");
      }
    }

    // Solve the puzzle
    int solutions = solve_puzzle(pieces, grid, 0);

    // Print the number of solutions
    printf("%d\n", solutions * 4);

    next_puzzle:;
  }

  return 0;
}