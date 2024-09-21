#include <stdio.h>
#include <string.h>

int main() {
  // Read the length of the game board and the state of the 1D-Go.
  int L;
  char S[101];
  scanf("%d %s", &L, S);

  // Initialize the maximum number of black stones that can be captured.
  int max_captured = 0;

  // Iterate over the game board.
  for (int i = 0; i < L; i++) {
    // If the current grid is empty, check if placing a white stone there would capture any black stones.
    if (S[i] == '.') {
      // Check for black stones to the left.
      int left_captured = 0;
      int j = i - 1;
      while (j >= 0 && S[j] == 'B') {
        left_captured++;
        j--;
      }
      // Check for black stones to the right.
      int right_captured = 0;
      j = i + 1;
      while (j < L && S[j] == 'B') {
        right_captured++;
        j++;
      }
      // Update the maximum number of captured black stones.
      if (left_captured + right_captured > max_captured) {
        max_captured = left_captured + right_captured;
      }
    }
  }

  // Print the maximum number of captured black stones.
  printf("%d\n", max_captured);

  return 0;
}