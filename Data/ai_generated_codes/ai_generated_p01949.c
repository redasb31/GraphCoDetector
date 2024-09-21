#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 50

// Structure to represent a cell on the grid
typedef struct {
  int row;
  int col;
  char value;
} Cell;

// Function to calculate the maximum value of the expression
long long calculate_max_value(char grid[MAX_SIZE][MAX_SIZE], int H, int W) {
  // Create a queue to store the cells to be explored
  Cell *queue[MAX_SIZE * MAX_SIZE];
  int front = 0, rear = 0;

  // Add the starting cell to the queue
  Cell *start = malloc(sizeof(Cell));
  start->row = 1;
  start->col = 1;
  start->value = grid[1][1];
  queue[rear++] = start;

  // Initialize the maximum value to the value of the starting cell
  long long max_value = (long long) start->value - '0';

  // Explore all possible paths from the starting cell to the ending cell
  while (front < rear) {
    // Get the current cell from the front of the queue
    Cell *current = queue[front++];

    // If the current cell is the ending cell, update the maximum value
    if (current->row == H && current->col == W) {
      max_value = (long long) current->value - '0';
      continue;
    }

    // Explore the right cell
    if (current->col < W) {
      Cell *right = malloc(sizeof(Cell));
      right->row = current->row;
      right->col = current->col + 1;
      right->value = grid[right->row][right->col];
      queue[rear++] = right;

      // Calculate the potential value if we move right
      long long potential_value = (long long) current->value - '0';
      if (current->value == '+') {
        potential_value += (long long) right->value - '0';
      } else if (current->value == '*') {
        potential_value *= (long long) right->value - '0';
      }

      // Update the maximum value if the potential value is greater
      if (potential_value > max_value) {
        max_value = potential_value;
      }
    }

    // Explore the down cell
    if (current->row < H) {
      Cell *down = malloc(sizeof(Cell));
      down->row = current->row + 1;
      down->col = current->col;
      down->value = grid[down->row][down->col];
      queue[rear++] = down;

      // Calculate the potential value if we move down
      long long potential_value = (long long) current->value - '0';
      if (current->value == '+') {
        potential_value += (long long) down->value - '0';
      } else if (current->value == '*') {
        potential_value *= (long long) down->value - '0';
      }

      // Update the maximum value if the potential value is greater
      if (potential_value > max_value) {
        max_value = potential_value;
      }
    }

    // Free the memory allocated for the current cell
    free(current);
  }

  // Return the maximum value
  return max_value;
}

int main() {
  int H, W;
  char grid[MAX_SIZE][MAX_SIZE];

  // Read the grid dimensions
  scanf("%d %d", &H, &W);

  // Read the grid characters
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      scanf(" %c", &grid[i][j]);
    }
  }

  // Calculate the maximum value of the expression
  long long max_value = calculate_max_value(grid, H, W);

  // Print the answer
  if (max_value <= LLONG_MAX) {
    printf("%lld\n", max_value);
  } else {
    printf("-1\n");
  }

  return 0;
}