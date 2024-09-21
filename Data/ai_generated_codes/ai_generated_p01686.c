#include <stdio.h>
#include <string.h>

#define MAX_M 1000
#define MAX_N 3 * MAX_M + 1

// Structure to represent a cell on the board
typedef struct {
  int row;
  int col;
} Cell;

// Function to check if a cell is a floor cell
int is_floor(char board[3][MAX_N], Cell cell) {
  return board[cell.row - 1][cell.col - 1] == '.';
}

// Function to check if a cell is painted
int is_painted(char board[3][MAX_N], Cell cell) {
  return board[cell.row - 1][cell.col - 1] >= 'A' && board[cell.row - 1][cell.col - 1] <= 'Z';
}

// Function to check if a cell is a wall cell
int is_wall(char board[3][MAX_N], Cell cell) {
  return board[cell.row - 1][cell.col - 1] >= 'a' && board[cell.row - 1][cell.col - 1] <= 'z';
}

// Function to get the color of a painted cell
int get_color(char board[3][MAX_N], Cell cell) {
  return board[cell.row - 1][cell.col - 1] - 'A' + 1;
}

// Function to toggle the state of a cell (floor to wall, wall to floor)
void toggle_cell(char board[3][MAX_N], Cell cell) {
  if (is_floor(board, cell)) {
    board[cell.row - 1][cell.col - 1] = board[cell.row - 1][cell.col - 1] + ('a' - 'A');
  } else if (is_wall(board, cell)) {
    board[cell.row - 1][cell.col - 1] = board[cell.row - 1][cell.col - 1] + ('A' - 'a');
  }
}

// Function to check if the token can reach the destination from the current cell
int can_reach(char board[3][MAX_N], Cell current, Cell destination) {
  // Initialize a visited array to track visited cells
  int visited[3][MAX_N] = {0};
  visited[current.row - 1][current.col - 1] = 1;

  // Perform a Depth-First Search (DFS) to explore possible paths
  Cell neighbors[4] = {
    {current.row - 1, current.col}, {current.row + 1, current.col},
    {current.row, current.col - 1}, {current.row, current.col + 1}
  };

  // Recursively explore neighbors
  for (int i = 0; i < 4; i++) {
    Cell neighbor = neighbors[i];

    // Check if neighbor is within the board and a valid floor cell
    if (neighbor.row >= 1 && neighbor.row <= 3 &&
        neighbor.col >= 1 && neighbor.col <= 3 * M + 1 &&
        !visited[neighbor.row - 1][neighbor.col - 1] &&
        is_floor(board, neighbor)) {
      visited[neighbor.row - 1][neighbor.col - 1] = 1;

      // If the neighbor is the destination, return true
      if (neighbor.row == destination.row && neighbor.col == destination.col) {
        return 1;
      }

      // Recursively explore from the neighbor
      if (can_reach(board, neighbor, destination)) {
        return 1;
      }
    }
  }

  // No path found
  return 0;
}

// Function to solve the problem
void solve(char board[3][MAX_N], int M) {
  // Initialize the starting and destination cells
  Cell start = {2, 1};
  Cell destination = {2, 3 * M + 1};

  // Initialize a set of switches to push
  int switches[26] = {0};
  int num_switches = 0;

  // Iterate through all possible combinations of switches
  for (int i = 0; i < (1 << 26); i++) {
    // Reset the board to its initial state
    for (int row = 1; row <= 3; row++) {
      for (int col = 1; col <= 3 * M + 1; col++) {
        board[row - 1][col - 1] = board[row - 1][col - 1];
      }
    }

    // Toggle switches based on the current combination
    for (int j = 0; j < 26; j++) {
      if (i & (1 << j)) {
        switches[j] = 1;
        num_switches++;

        // Toggle all cells of color (j + 1)
        for (int row = 1; row <= 3; row++) {
          for (int col = 1; col <= 3 * M + 1; col++) {
            Cell cell = {row, col};
            if (is_painted(board, cell) && get_color(board, cell) == j + 1) {
              toggle_cell(board, cell);
            }
          }
        }
      }
    }

    // Check if the token can reach the destination with the current switch configuration
    if (can_reach(board, start, destination)) {
      // Output the set of switches pushed
      printf("%d ", num_switches);
      for (int j = 0; j < 26; j++) {
        if (switches[j]) {
          printf("%c ", j + 'A');
        }
      }
      printf("\n");
      return;
    }

    // Reset the switches for the next combination
    memset(switches, 0, sizeof(switches));
    num_switches = 0;
  }

  // No solution found
  printf("-1\n");
}

int main() {
  int M;
  char board[3][MAX_N];

  // Read input
  while (scanf("%d", &M) && M != 0) {
    for (int i = 0; i < 3; i++) {
      scanf("%s", board[i]);
    }

    // Solve the problem
    solve(board, M);
  }

  return 0;
}