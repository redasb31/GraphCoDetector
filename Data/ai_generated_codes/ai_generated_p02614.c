#include <stdio.h>

int main() {
  int H, W, K;
  scanf("%d %d %d", &H, &W, &K);

  // Grid to store the input
  char grid[6][6];

  // Read the grid
  for (int i = 0; i < H; i++) {
    scanf("%s", grid[i]);
  }

  // Count initial black squares
  int black_squares = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == '#') {
        black_squares++;
      }
    }
  }

  // Calculate combinations for rows and columns
  int combinations = 0;
  for (int i = 0; i <= H; i++) {
    for (int j = 0; j <= W; j++) {
      // Calculate the number of black squares remaining after painting
      int remaining_black_squares = black_squares - i * W - j * H + i * j;

      // If the number of remaining black squares is equal to K, increment the combinations
      if (remaining_black_squares == K) {
        combinations++;
      }
    }
  }

  // Print the number of combinations
  printf("%d\n", combinations);

  return 0;
}