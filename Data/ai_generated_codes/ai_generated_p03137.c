#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum number of moves required
int minMoves(int N, int M, int *X) {
  // Sort the target coordinates in ascending order
  qsort(X, M, sizeof(int), compare);

  // Initialize the current position of the leftmost piece
  int left = X[0];

  // Initialize the current position of the rightmost piece
  int right = X[M - 1];

  // Initialize the number of moves
  int moves = 0;

  // Iterate over the target coordinates
  for (int i = 1; i < M; i++) {
    // If the next target coordinate is within the reach of the leftmost piece
    if (X[i] <= left + N - 1) {
      // Move the leftmost piece to the next target coordinate
      moves += X[i] - left;
      left = X[i];
    }
    // If the next target coordinate is within the reach of the rightmost piece
    else if (X[i] >= right - N + 1) {
      // Move the rightmost piece to the next target coordinate
      moves += right - X[i];
      right = X[i];
    }
    // If the next target coordinate is not within the reach of either piece
    else {
      // Move the leftmost piece to the rightmost piece
      moves += right - left;
      left = right;
      // Move the rightmost piece to the next target coordinate
      moves += X[i] - right;
      right = X[i];
    }
  }

  // Return the minimum number of moves
  return moves;
}

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  // Input the number of pieces and target coordinates
  int N, M;
  scanf("%d %d", &N, &M);

  // Allocate memory for the target coordinates
  int *X = (int *)malloc(M * sizeof(int));

  // Input the target coordinates
  for (int i = 0; i < M; i++) {
    scanf("%d", &X[i]);
  }

  // Calculate the minimum number of moves
  int moves = minMoves(N, M, X);

  // Output the minimum number of moves
  printf("%d\n", moves);

  // Free the allocated memory
  free(X);

  return 0;
}