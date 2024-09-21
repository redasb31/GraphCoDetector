#include <stdio.h>
#include <string.h>

#define MAX_H 12
#define MAX_W 12

int main() {
  int H, W;
  char S[MAX_H][MAX_W + 1];

  // Input
  scanf("%d %d", &H, &W);
  for (int i = 0; i < H; i++) {
    scanf("%s", S[i]);
  }

  // Check if the grid can be made symmetric
  int is_symmetric = 1;
  for (int i = 0; i < H / 2; i++) {
    for (int j = 0; j < W / 2; j++) {
      // Check if the corresponding squares are equal after swapping rows and columns
      if (S[i][j] != S[H - i - 1][W - j - 1] ||
          S[H - i - 1][j] != S[i][W - j - 1]) {
        is_symmetric = 0;
        break;
      }
    }
    if (!is_symmetric) {
      break;
    }
  }

  // Output
  if (is_symmetric) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}