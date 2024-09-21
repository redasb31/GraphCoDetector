#include <stdio.h>
#include <stdlib.h>

// Function to calculate Manhattan distance between two points
int manhattan_distance(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

// Function to check if the game can be finished and find the optimal solution
int solve(int X, int Y, int K) {
  // Check if the goal is reachable
  if (abs(X) + abs(Y) % K != 0) {
    return -1; // Game cannot be finished
  }

  // Calculate the number of strokes required
  int strokes = (abs(X) + abs(Y)) / K;

  // Print the optimal solution
  printf("Yes\n");
  printf("%d\n", strokes);

  // Calculate the current position of the ball
  int x = 0, y = 0;

  // Iterate over the strokes
  for (int i = 0; i < strokes; i++) {
    // Calculate the direction to move the ball
    int dx = (X > 0) ? K : (X < 0) ? -K : 0;
    int dy = (Y > 0) ? K : (Y < 0) ? -K : 0;

    // Move the ball
    x += dx;
    y += dy;

    // Print the movement
    printf("%d %d\n", x, y);

    // Update X and Y
    X -= dx;
    Y -= dy;
  }

  return 0; // Game finished successfully
}

int main() {
  int X, Y, K;

  // Input the goal coordinates and K value
  scanf("%d %d %d", &X, &Y, &K);

  // Solve the game and print the result
  int result = solve(X, Y, K);

  // If the game cannot be finished
  if (result == -1) {
    printf("No\n");
  }

  return 0;
}