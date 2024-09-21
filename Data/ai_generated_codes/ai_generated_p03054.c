#include <stdio.h>
#include <string.h>

int main() {
  int H, W, N, s_r, s_c;
  char S[200001], T[200001];

  // Read input
  scanf("%d %d %d\n", &H, &W, &N);
  scanf("%d %d\n", &s_r, &s_c);
  scanf("%s\n", S);
  scanf("%s", T);

  // Initialize current position
  int r = s_r, c = s_c;

  // Simulate the game
  for (int i = 0; i < N; i++) {
    // Takahashi's move
    if (S[i] == 'L' && c > 1) {
      c--; // Move left
    } else if (S[i] == 'R' && c < W) {
      c++; // Move right
    } else if (S[i] == 'U' && r > 1) {
      r--; // Move up
    } else if (S[i] == 'D' && r < H) {
      r++; // Move down
    }

    // Check if piece is removed after Takahashi's move
    if (r < 1 || r > H || c < 1 || c > W) {
      printf("NO\n");
      return 0;
    }

    // Aoki's move
    if (T[i] == 'L' && c > 1) {
      c--; // Move left
    } else if (T[i] == 'R' && c < W) {
      c++; // Move right
    } else if (T[i] == 'U' && r > 1) {
      r--; // Move up
    } else if (T[i] == 'D' && r < H) {
      r++; // Move down
    }

    // Check if piece is removed after Aoki's move
    if (r < 1 || r > H || c < 1 || c > W) {
      printf("NO\n");
      return 0;
    }
  }

  // If the piece is still on the grid after N steps
  printf("YES\n");
  return 0;
}