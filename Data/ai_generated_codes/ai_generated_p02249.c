#include <stdio.h>
#include <string.h>

#define MAX_H 1000
#define MAX_W 1000

int main() {
  // Declare variables for region size
  int H, W;

  // Declare variables for pattern size
  int R, C;

  // Declare arrays to store region and pattern
  char region[MAX_H][MAX_W];
  char pattern[MAX_H][MAX_W];

  // Read the region size
  scanf("%d %d", &H, &W);

  // Read the region
  for (int i = 0; i < H; i++) {
    scanf("%s", region[i]);
  }

  // Read the pattern size
  scanf("%d %d", &R, &C);

  // Read the pattern
  for (int i = 0; i < R; i++) {
    scanf("%s", pattern[i]);
  }

  // Iterate over the region to find the pattern
  for (int i = 0; i <= H - R; i++) {
    for (int j = 0; j <= W - C; j++) {
      // Check if the pattern is found at the current position
      int found = 1;
      for (int k = 0; k < R && found; k++) {
        for (int l = 0; l < C && found; l++) {
          if (region[i + k][j + l] != pattern[k][l]) {
            found = 0;
          }
        }
      }

      // Print the coordinates if the pattern is found
      if (found) {
        printf("%d %d\n", i, j);
      }
    }
  }

  return 0;
}