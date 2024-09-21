#include <stdio.h>

int main() {
  // N: Number of squares
  // M: Number of toll gates
  // X: Starting square
  int N, M, X;
  scanf("%d %d %d", &N, &M, &X);

  // A: Array of toll gate positions
  int A[100];
  for (int i = 0; i < M; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the minimum cost to reach the goal (Square 0 or Square N)
  int min_cost = 0;
  int current_square = X;
  // Iterate through the toll gates
  for (int i = 0; i < M; i++) {
    // Check if the current square is before or after the toll gate
    if (current_square < A[i]) {
      // If the current square is before the toll gate, move to the left
      min_cost += A[i] - current_square;
      current_square = A[i];
      // Check if we have reached the goal
      if (current_square == 0) {
        break;
      }
    } else {
      // If the current square is after the toll gate, move to the right
      min_cost += current_square - A[i];
      current_square = A[i];
      // Check if we have reached the goal
      if (current_square == N) {
        break;
      }
    }
  }

  // If we have not reached the goal yet, move to the remaining goal
  if (current_square != 0 && current_square != N) {
    min_cost += (current_square < N / 2) ? current_square : N - current_square;
  }

  // Print the minimum cost
  printf("%d\n", min_cost);

  return 0;
}