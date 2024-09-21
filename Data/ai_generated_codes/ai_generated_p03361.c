#include <stdio.h>
#include <stdbool.h>

#define MAX_H 50
#define MAX_W 50

int main() {
  int H, W;
  char grid[MAX_H][MAX_W];
  
  // Read input
  scanf("%d %d", &H, &W);
  for (int i = 0; i < H; i++) {
    scanf("%s", grid[i]);
  }

  // Check if the grid is valid
  bool valid = true;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] != '#' && grid[i][j] != '.') {
        valid = false;
        break;
      }
    }
    if (!valid) {
      break;
    }
  }

  if (!valid) {
    printf("No\n");
    return 0;
  }

  // Check if it's possible to paint the grid
  bool possible = true;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      // If the current square is black, but the adjacent squares are not, it's impossible
      if (grid[i][j] == '#' && 
          (i > 0 && grid[i - 1][j] == '.' ||
           i < H - 1 && grid[i + 1][j] == '.' ||
           j > 0 && grid[i][j - 1] == '.' ||
           j < W - 1 && grid[i][j + 1] == '.')) {
        possible = false;
        break;
      }
    }
    if (!possible) {
      break;
    }
  }

  // Print the result
  if (possible) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}