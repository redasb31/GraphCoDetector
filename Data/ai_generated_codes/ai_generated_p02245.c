#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3 // Size of the puzzle

// Structure to represent a state of the puzzle
typedef struct {
  int puzzle[N][N]; // The puzzle state
  int steps;        // Number of steps taken to reach this state
} State;

// Function to check if the given state is the goal state
int isGoal(State state) {
  int goal[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (state.puzzle[i][j] != goal[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}

// Function to print the puzzle state
void printPuzzle(State state) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", state.puzzle[i][j]);
    }
    printf("\n");
  }
}

// Function to find the position of the empty space (0) in the puzzle
void findEmpty(State state, int *row, int *col) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (state.puzzle[i][j] == 0) {
        *row = i;
        *col = j;
        return;
      }
    }
  }
}

// Function to generate new states by moving the empty space
void generateStates(State current, State *states) {
  int row, col;
  findEmpty(current, &row, &col);

  // Move up
  if (row > 0) {
    states[0] = current;
    states[0].puzzle[row][col] = states[0].puzzle[row - 1][col];
    states[0].puzzle[row - 1][col] = 0;
    states[0].steps++;
  }

  // Move down
  if (row < N - 1) {
    states[1] = current;
    states[1].puzzle[row][col] = states[1].puzzle[row + 1][col];
    states[1].puzzle[row + 1][col] = 0;
    states[1].steps++;
  }

  // Move left
  if (col > 0) {
    states[2] = current;
    states[2].puzzle[row][col] = states[2].puzzle[row][col - 1];
    states[2].puzzle[row][col - 1] = 0;
    states[2].steps++;
  }

  // Move right
  if (col < N - 1) {
    states[3] = current;
    states[3].puzzle[row][col] = states[3].puzzle[row][col + 1];
    states[3].puzzle[row][col + 1] = 0;
    states[3].steps++;
  }
}

// Function to implement the Breadth-First Search (BFS) algorithm to solve the puzzle
int solvePuzzle(State initial) {
  State *queue = (State *)malloc(sizeof(State) * 1000); // Queue to store states
  int front = 0, rear = 0;
  queue[rear++] = initial; // Enqueue the initial state

  while (front < rear) {
    State current = queue[front++];
    if (isGoal(current)) {
      free(queue);
      return current.steps;
    }

    // Generate new states
    State states[4];
    generateStates(current, states);

    // Enqueue the new states
    for (int i = 0; i < 4; i++) {
      if (states[i].puzzle[0][0] != -1) { // Check if the state is valid
        queue[rear++] = states[i];
      }
    }
  }

  free(queue);
  return -1; // No solution found
}

int main() {
  State initial;
  // Read the initial puzzle state
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &initial.puzzle[i][j]);
    }
  }

  initial.steps = 0;
  int steps = solvePuzzle(initial);

  if (steps == -1) {
    printf("No solution found.\n");
  } else {
    printf("%d\n", steps);
  }

  return 0;
}