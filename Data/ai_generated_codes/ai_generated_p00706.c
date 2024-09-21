#include <stdio.h>

// Function to calculate the number of persimmon trees within a given estate
int count_trees(int x1, int y1, int x2, int y2, int N, int *X, int *Y) {
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (X[i] >= x1 && X[i] <= x2 && Y[i] >= y1 && Y[i] <= y2) {
      count++;
    }
  }
  return count;
}

int main() {
  int N, W, H, S, T;
  int x[500], y[500]; // Array to store tree coordinates

  while (1) {
    scanf("%d", &N);
    if (N == 0) break;

    scanf("%d %d", &W, &H);

    // Read the coordinates of the persimmon trees
    for (int i = 0; i < N; i++) {
      scanf("%d %d", &x[i], &y[i]);
    }

    scanf("%d %d", &S, &T);

    // Calculate the maximum number of trees in an estate
    int max_trees = 0;
    for (int i = 1; i <= W - S + 1; i++) {
      for (int j = 1; j <= H - T + 1; j++) {
        int trees = count_trees(i, j, i + S - 1, j + T - 1, N, x, y);
        if (trees > max_trees) {
          max_trees = trees;
        }
      }
    }

    printf("%d\n", max_trees);
  }

  return 0;
}