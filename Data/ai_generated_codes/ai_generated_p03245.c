#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_M 40

typedef struct {
  int x, y;
} Point;

Point points[MAX_N];
int N;

int d[MAX_M];
char modes[MAX_M];

int solve() {
  // Try different arm lengths (m)
  for (int m = 1; m <= MAX_M; m++) {
    // Try different section lengths (d_i)
    for (int i = 1; i <= m; i++) {
      d[i] = i;  // Initialize section length to i
    }
    // Try different mode combinations
    for (int i = 0; i < (1 << (2 * m)); i++) {
      // Generate mode string
      for (int j = 0; j < m; j++) {
        if (i & (1 << (2 * j))) {
          modes[j] = 'R';
        } else if (i & (1 << (2 * j + 1))) {
          modes[j] = 'U';
        } else {
          modes[j] = 'L';
        }
      }
      // Check if this arm can reach all points
      int valid = 1;
      for (int j = 0; j < N; j++) {
        int x = 0, y = 0;
        for (int k = 0; k < m; k++) {
          switch (modes[k]) {
            case 'L': x -= d[k + 1]; y -= d[k + 1]; break;
            case 'R': x += d[k + 1]; y -= d[k + 1]; break;
            case 'D': x -= d[k + 1]; y += d[k + 1]; break;
            case 'U': x += d[k + 1]; y += d[k + 1]; break;
          }
        }
        if (x != points[j].x || y != points[j].y) {
          valid = 0;
          break;
        }
      }
      if (valid) {
        // Print the solution
        printf("%d\n", m);
        for (int i = 1; i <= m; i++) {
          printf("%d ", d[i]);
        }
        printf("\n");
        for (int j = 0; j < N; j++) {
          for (int k = 0; k < m; k++) {
            printf("%c", modes[k]);
          }
          printf("\n");
        }
        return 0;
      }
    }
  }
  // No solution found
  printf("-1\n");
  return 0;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &points[i].x, &points[i].y);
  }
  solve();
  return 0;
}