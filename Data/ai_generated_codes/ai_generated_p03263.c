#include <stdio.h>

#define MAX_H 500
#define MAX_W 500

int main() {
  int H, W;
  int a[MAX_H][MAX_W];
  int operations[MAX_H * MAX_W][4];
  int operationCount = 0;

  // Input
  scanf("%d %d", &H, &W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  // Iterate through the grid and perform operations
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      // If the cell has an odd number of coins
      if (a[i][j] % 2 != 0) {
        // Find a neighboring cell with an odd number of coins
        if (i > 0 && a[i - 1][j] % 2 != 0) {
          // Move a coin from the current cell to the neighboring cell
          a[i][j]--;
          a[i - 1][j]++;
          operations[operationCount][0] = i + 1;
          operations[operationCount][1] = j + 1;
          operations[operationCount][2] = i;
          operations[operationCount][3] = j + 1;
          operationCount++;
        } else if (i < H - 1 && a[i + 1][j] % 2 != 0) {
          // Move a coin from the current cell to the neighboring cell
          a[i][j]--;
          a[i + 1][j]++;
          operations[operationCount][0] = i + 1;
          operations[operationCount][1] = j + 1;
          operations[operationCount][2] = i + 2;
          operations[operationCount][3] = j + 1;
          operationCount++;
        } else if (j > 0 && a[i][j - 1] % 2 != 0) {
          // Move a coin from the current cell to the neighboring cell
          a[i][j]--;
          a[i][j - 1]++;
          operations[operationCount][0] = i + 1;
          operations[operationCount][1] = j + 1;
          operations[operationCount][2] = i + 1;
          operations[operationCount][3] = j;
          operationCount++;
        } else if (j < W - 1 && a[i][j + 1] % 2 != 0) {
          // Move a coin from the current cell to the neighboring cell
          a[i][j]--;
          a[i][j + 1]++;
          operations[operationCount][0] = i + 1;
          operations[operationCount][1] = j + 1;
          operations[operationCount][2] = i + 1;
          operations[operationCount][3] = j + 2;
          operationCount++;
        }
      }
    }
  }

  // Output
  printf("%d\n", operationCount);
  for (int i = 0; i < operationCount; i++) {
    printf("%d %d %d %d\n", operations[i][0], operations[i][1], operations[i][2], operations[i][3]);
  }

  return 0;
}