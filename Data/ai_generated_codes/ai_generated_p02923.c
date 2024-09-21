#include <stdio.h>

int main() {
  int N; // Number of squares
  scanf("%d", &N);

  int H[100000]; // Array to store heights of squares
  for (int i = 0; i < N; i++) {
    scanf("%d", &H[i]);
  }

  int max_moves = 0; // Initialize maximum moves to 0

  // Iterate through each square as a starting point
  for (int i = 0; i < N; i++) {
    int current_moves = 0; // Initialize moves for current starting point
    int j = i; // Start from the current square

    // Move to the right as long as the height of the next square is not greater
    while (j < N - 1 && H[j] >= H[j + 1]) {
      current_moves++;
      j++;
    }

    // Update the maximum moves if current moves are greater
    if (current_moves > max_moves) {
      max_moves = current_moves;
    }
  }

  printf("%d\n", max_moves); // Print the maximum number of moves
  return 0;
}