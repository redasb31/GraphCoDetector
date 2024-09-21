#include <stdio.h>

int main() {
  // Declare variables for grid dimensions and target black squares.
  int H, W, N;

  // Read input values from standard input.
  scanf("%d", &H);
  scanf("%d", &W);
  scanf("%d", &N);

  // Calculate the minimum number of operations needed.
  // The minimum operations are required when we paint alternate rows/columns.
  int operations = (N + (H / 2) + (W / 2) - 1) / (H + W); 

  // Print the result.
  printf("%d\n", operations);

  return 0;
}