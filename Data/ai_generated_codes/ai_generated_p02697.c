#include <stdio.h>

int main() {
  // Input
  int N, M;
  scanf("%d %d", &N, &M);

  // Assign players to playing fields
  for (int i = 0; i < M; i++) {
    // Assign the first player to the playing field
    int a = i * 2 + 1; // Calculate the first player's integer
    if (a > N) { // If the integer exceeds N, wrap around
      a = a - N;
    }
    // Assign the second player to the playing field
    int b = i * 2 + 2; // Calculate the second player's integer
    if (b > N) { // If the integer exceeds N, wrap around
      b = b - N;
    }
    // Print the assigned players
    printf("%d %d\n", a, b);
  }

  return 0;
}