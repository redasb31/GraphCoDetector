#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 20
#define MAX_MOVES 10

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  Position position;
  int moves;
} State;

// Function to print the board for debugging
void printBoard(int board[][MAX_WIDTH], int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a position is valid on the board
bool isValidPosition(int width, int height, Position position) {
  return (position.x >= 0 && position.x < width &&
          position.y >= 0 && position.y < height);
}

// Function to find the shortest path from start to goal using Breadth-First Search (BFS)
int findShortestPath(int board[][MAX_WIDTH], int width, int height,
                   Position start, Position goal) {
  // Create a queue for BFS
  State queue[MAX_WIDTH * MAX_HEIGHT];
  int front = 0, rear = 0;

  // Create a visited array to keep track of visited positions
  bool visited[MAX_HEIGHT][MAX_WIDTH] = {{false}};

  // Initialize the starting state
  queue[rear].position = start;
  queue[rear].moves = 0;
  rear++;
  visited[start.y][start.x] = true;

  // Perform BFS
  while (front < rear) {
    State current = queue[front];
    front++;

    // Check if the goal is reached
    if (current.position.x == goal.x && current.position.y == goal.y) {
      return current.moves;
    }

    // Explore the four possible directions
    Position nextPositions[] = {{current.position.x + 1, current.position.y},
                              {current.position.x - 1, current.position.y},
                              {current.position.x, current.position.y + 1},
                              {current.position.x, current.position.y - 1}};
    for (int i = 0; i < 4; i++) {
      Position nextPosition = nextPositions[i];
      // Check if the next position is valid and not visited
      if (isValidPosition(width, height, nextPosition) &&
          !visited[nextPosition.y][nextPosition.x] &&
          board[nextPosition.y][nextPosition.x] != 1) {
        // Update the board after moving the stone
        board[nextPosition.y][nextPosition.x] = board[current.position.y][current.position.x];
        board[current.position.y][current.position.x] = 0;

        // Add the next state to the queue
        queue[rear].position = nextPosition;
        queue[rear].moves = current.moves + 1;
        rear++;
        visited[nextPosition.y][nextPosition.x] = true;

        // Restore the board after exploring the next position
        board[current.position.y][current.position.x] = board[nextPosition.y][nextPosition.x];
        board[nextPosition.y][nextPosition.x] = 0;
      }
    }
  }

  // If the goal is not reached within the maximum moves, return -1
  return -1;
}

int main() {
  int width, height;
  int board[MAX_HEIGHT][MAX_WIDTH];
  Position start, goal;

  while (1) {
    scanf("%d %d", &width, &height);
    if (width == 0 && height == 0) {
      break;
    }

    // Read the board configuration
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        scanf("%d", &board[i][j]);
        // Find the start and goal positions
        if (board[i][j] == 2) {
          start.x = j;
          start.y = i;
        } else if (board[i][j] == 3) {
          goal.x = j;
          goal.y = i;
        }
      }
    }

    // Find the shortest path
    int shortestPath = findShortestPath(board, width, height, start, goal);

    // Print the result
    printf("%d\n", shortestPath);
  }

  return 0;
}