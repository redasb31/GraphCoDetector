#include <stdio.h>
#include <limits.h>

// Function to check if a given set of keys can unlock all boxes
int canUnlockAll(int N, int M, int a[], int b[], int c[][N]) {
  int unlocked[N + 1] = {0}; // Array to track unlocked boxes
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < b[i]; j++) {
      unlocked[c[i][j]] = 1; // Mark the box as unlocked
    }
  }
  for (int i = 1; i <= N; i++) {
    if (!unlocked[i]) {
      return 0; // If any box is not unlocked, return 0
    }
  }
  return 1; // All boxes are unlocked
}

// Function to find the minimum cost to unlock all boxes
int findMinCost(int N, int M, int a[], int b[], int c[][N]) {
  int minCost = INT_MAX; // Initialize the minimum cost to infinity
  for (int i = 0; i < (1 << M); i++) { // Iterate through all possible combinations of keys
    int cost = 0;
    int keysUsed[M] = {0}; // Array to track which keys are used
    for (int j = 0; j < M; j++) {
      if (i & (1 << j)) { // Check if the j-th key is selected
        cost += a[j];
        keysUsed[j] = 1; // Mark the j-th key as used
      }
    }
    if (canUnlockAll(N, M, a, b, c) && cost < minCost) {
      minCost = cost; // Update the minimum cost
    }
  }
  if (minCost == INT_MAX) {
    return -1; // If no combination of keys can unlock all boxes
  }
  return minCost; // Return the minimum cost
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  int a[M], b[M];
  int c[M][N]; // Array to store the boxes unlocked by each key

  // Read the input
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &a[i], &b[i]);
    for (int j = 0; j < b[i]; j++) {
      scanf("%d", &c[i][j]);
    }
  }

  // Calculate the minimum cost
  int minCost = findMinCost(N, M, a, b, c);

  // Print the output
  printf("%d\n", minCost);

  return 0;
}