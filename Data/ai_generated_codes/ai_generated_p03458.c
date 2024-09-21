#include <stdio.h>

int main() {
  // N: Number of desires
  // K: Side length of the checked pattern
  int N, K;
  scanf("%d %d", &N, &K);

  // Store desires (x, y, color)
  int x[100000], y[100000];
  char c[100000];

  // Read desires
  for (int i = 0; i < N; i++) {
    scanf("%d %d %c", &x[i], &y[i], &c[i]);
  }

  // Count satisfiable desires
  int count = 0;
  for (int i = 0; i < N; i++) {
    // Calculate the grid coordinates (row, col)
    int row = x[i] / K;
    int col = y[i] / K;

    // Calculate the expected color based on grid coordinates
    int expectedColor = (row + col) % 2; 
    // 0: Black, 1: White

    // Check if the desire matches the expected color
    if (c[i] == 'B' && expectedColor == 0 || c[i] == 'W' && expectedColor == 1) {
      count++; // Satisfiable desire
    }
  }

  printf("%d\n", count);
  return 0;
}