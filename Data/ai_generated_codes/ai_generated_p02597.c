#include <stdio.h>
#include <string.h>

int main() {
  // N: number of stones
  int N;
  // c: array of stone colors (R = red, W = white)
  char c[200001];

  // Read input
  scanf("%d", &N);
  scanf("%s", c);

  // Count initial white stones
  int white_count = 0;
  for (int i = 0; i < N; i++) {
    if (c[i] == 'W') {
      white_count++;
    }
  }

  // Calculate minimum operations
  // We can minimize operations by moving all white stones to the right side
  // and changing color of red stones on the left side.
  int operations = 0;

  // Count red stones on left side
  int red_count = 0;
  for (int i = 0; i < N; i++) {
    if (c[i] == 'R') {
      red_count++;
    } else {
      // White stone found.
      // Swap with the red stone on the right side to avoid disaster.
      operations += red_count;
      // If all red stones on the left side are moved, change its color
      // to avoid disaster with the next white stone.
      operations += (red_count > 0) ? 1 : 0;
      red_count = 0;
    }
  }

  // If there are any red stones on the left side,
  // we need to change their color to avoid disaster.
  operations += red_count;

  // Print result
  printf("%d\n", operations);

  return 0;
}