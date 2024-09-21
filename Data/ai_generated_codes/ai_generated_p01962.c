#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a coin
typedef struct {
  int radius;
  int sx, sy;
  int tx, ty;
} Coin;

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to check if two coins collide
int checkCollision(Coin c1, Coin c2) {
  // Calculate the distance between the centers of the two coins
  double dist = distance(c1.sx, c1.sy, c2.sx, c2.sy);
  // Check if the distance is less than the sum of their radii
  return dist < c1.radius + c2.radius;
}

// Function to check if a coin collides with any other coin in a given list
int checkCollisionList(Coin coin, Coin *coins, int n) {
  for (int i = 0; i < n; i++) {
    // Ignore the coin itself
    if (i == coin.radius) {
      continue;
    }
    // Check if the coin collides with any other coin
    if (checkCollision(coin, coins[i])) {
      return 1;
    }
  }
  return 0;
}

// Function to find the maximum score of the puzzle
int findMaxScore(Coin *coins, int n) {
  int score = 0;
  // Create a copy of the coins array
  Coin *temp_coins = malloc(n * sizeof(Coin));
  if (temp_coins == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  for (int i = 0; i < n; i++) {
    temp_coins[i] = coins[i];
  }

  // Iterate over the coins
  for (int i = 0; i < n; i++) {
    // Check if the coin can be moved
    if (!checkCollisionList(temp_coins[i], temp_coins, n)) {
      // Move the coin to its target position
      temp_coins[i].sx = temp_coins[i].tx;
      temp_coins[i].sy = temp_coins[i].ty;
      score++;
    }
  }

  free(temp_coins);
  return score;
}

int main() {
  int n;
  scanf("%d", &n);

  // Allocate memory for the coins
  Coin *coins = malloc(n * sizeof(Coin));
  if (coins == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  // Read the input for each coin
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d %d",
          &coins[i].radius,
          &coins[i].sx,
          &coins[i].sy,
          &coins[i].tx,
          &coins[i].ty);
  }

  // Find the maximum score
  int maxScore = findMaxScore(coins, n);

  // Print the maximum score
  printf("%d\n", maxScore);

  // Free the allocated memory
  free(coins);

  return 0;
}