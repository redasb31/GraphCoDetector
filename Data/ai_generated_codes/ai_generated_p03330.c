#include <stdio.h>
#include <limits.h>

#define MAX_N 500
#define MAX_C 30

int N, C;
int D[MAX_C][MAX_C];
int c[MAX_N][MAX_N];

int min(int a, int b) {
  return (a < b) ? a : b;
}

int main() {
  // Input
  scanf("%d %d", &N, &C);
  for (int i = 1; i <= C; i++) {
    for (int j = 1; j <= C; j++) {
      scanf("%d", &D[i][j]);
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &c[i][j]);
    }
  }

  // Calculate minimum wrongness
  int wrongness = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      // Find the optimal color for this square
      int best_color = c[i][j];
      int min_wrongness = INT_MAX;
      for (int k = 1; k <= C; k++) {
        int current_wrongness = 0;
        for (int x = 1; x <= N; x++) {
          for (int y = 1; y <= N; y++) {
            // Check if (i, j) and (x, y) need to have the same color
            if (((i + j) % 3) == ((x + y) % 3)) {
              if (k != c[x][y]) {
                current_wrongness += D[k][c[x][y]];
              }
            } else {
              // Check if (i, j) and (x, y) need to have different colors
              if (k == c[x][y]) {
                current_wrongness += D[k][c[x][y]];
              }
            }
          }
        }
        if (current_wrongness < min_wrongness) {
          min_wrongness = current_wrongness;
          best_color = k;
        }
      }

      // Update wrongness and color
      wrongness += D[c[i][j]][best_color];
      c[i][j] = best_color;
    }
  }

  // Output
  printf("%d\n", wrongness);

  return 0;
}