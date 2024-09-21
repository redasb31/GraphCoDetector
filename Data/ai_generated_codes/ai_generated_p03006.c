#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a ball
typedef struct {
  int x;
  int y;
} Ball;

// Function to find the minimum cost of collecting all balls
int minCost(Ball *balls, int n) {
  // Initialize minimum cost to infinity
  int minCost = INT_MAX;

  // Iterate over all possible values of p and q
  for (int p = -1000000000; p <= 1000000000; p++) {
    for (int q = -1000000000; q <= 1000000000; q++) {
      // Skip if both p and q are 0
      if (p == 0 && q == 0) {
        continue;
      }

      // Initialize cost for current p and q
      int cost = 0;

      // Create a boolean array to track collected balls
      int *collected = (int *)calloc(n, sizeof(int));

      // Iterate over all balls
      for (int i = 0; i < n; i++) {
        // Check if the ball has already been collected
        if (collected[i]) {
          continue;
        }

        // Check if the ball can be collected for free
        int prevX = balls[i].x - p;
        int prevY = balls[i].y - q;
        int j;
        for (j = 0; j < n; j++) {
          if (balls[j].x == prevX && balls[j].y == prevY && collected[j]) {
            break;
          }
        }

        // If the ball cannot be collected for free, increment cost
        if (j == n) {
          cost++;
        }

        // Mark the current ball as collected
        collected[i] = 1;
      }

      // Update minimum cost if current cost is less
      if (cost < minCost) {
        minCost = cost;
      }

      // Free the collected array
      free(collected);
    }
  }

  return minCost;
}

int main() {
  // Read the number of balls
  int n;
  scanf("%d", &n);

  // Allocate memory for the balls
  Ball *balls = (Ball *)malloc(n * sizeof(Ball));

  // Read the coordinates of the balls
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &balls[i].x, &balls[i].y);
  }

  // Find the minimum cost
  int cost = minCost(balls, n);

  // Print the minimum cost
  printf("%d\n", cost);

  // Free the memory allocated for the balls
  free(balls);

  return 0;
}