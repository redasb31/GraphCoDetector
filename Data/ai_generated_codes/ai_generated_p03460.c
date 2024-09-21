#include <stdio.h>

int main() {
  // N: Number of desires
  // K: Side length of the checked pattern
  int N, K;
  scanf("%d %d", &N, &K);

  // x, y: Coordinates of the desire
  // c: Color of the desire (B: Black, W: White)
  int x, y;
  char c;

  // Count of satisfiable desires
  int count = 0;

  // Iterate over all desires
  for (int i = 0; i < N; i++) {
    scanf("%d %d %c", &x, &y, &c);

    // Calculate the coordinates of the top-left corner of the K x K square containing the desired square
    int topLeftX = x - (x % K);
    int topLeftY = y - (y % K);

    // Check if the desired color matches the color of the square determined by the top-left corner
    if (((topLeftX / K) + (topLeftY / K)) % 2 == 0 && c == 'B') {
      // Black square
      count++;
    } else if (((topLeftX / K) + (topLeftY / K)) % 2 == 1 && c == 'W') {
      // White square
      count++;
    }
  }

  // Print the maximum number of satisfiable desires
  printf("%d\n", count);

  return 0;
}