#include <stdio.h>
#include <string.h>

#define MAX_H 2000
#define MAX_W 2000

int main() {
  int H, W;
  char S[MAX_H][MAX_W + 1];

  // Input the grid dimensions and the grid itself
  scanf("%d %d\n", &H, &W);
  for (int i = 0; i < H; i++) {
    scanf("%s\n", S[i]);
  }

  // Initialize the maximum number of lighted squares to 0
  int max_lighted = 0;

  // Iterate through each square in the grid
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      // Skip if the current square has an obstacle
      if (S[i][j] == '#') {
        continue;
      }

      // Calculate the number of squares lighted in each direction
      int lighted_up = 0, lighted_down = 0, lighted_left = 0, lighted_right = 0;

      // Light up squares in the upward direction
      for (int k = i - 1; k >= 0; k--) {
        if (S[k][j] == '#') {
          break;
        }
        lighted_up++;
      }

      // Light up squares in the downward direction
      for (int k = i + 1; k < H; k++) {
        if (S[k][j] == '#') {
          break;
        }
        lighted_down++;
      }

      // Light up squares in the leftward direction
      for (int k = j - 1; k >= 0; k--) {
        if (S[i][k] == '#') {
          break;
        }
        lighted_left++;
      }

      // Light up squares in the rightward direction
      for (int k = j + 1; k < W; k++) {
        if (S[i][k] == '#') {
          break;
        }
        lighted_right++;
      }

      // Calculate the total number of squares lighted for the current position
      int lighted = lighted_up + lighted_down + lighted_left + lighted_right + 1; // +1 for the lamp itself

      // Update the maximum number of lighted squares if necessary
      if (lighted > max_lighted) {
        max_lighted = lighted;
      }
    }
  }

  // Print the maximum number of lighted squares
  printf("%d\n", max_lighted);

  return 0;
}