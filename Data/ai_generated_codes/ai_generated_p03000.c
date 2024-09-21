#include <stdio.h>

int main() {
  // N: Number of bounces (excluding the first one)
  // X: Maximum coordinate for counting bounces
  int N, X;
  scanf("%d %d", &N, &X);

  // L: Array to store the lengths of each bounce
  int L[N];

  // Read the lengths of each bounce
  for (int i = 0; i < N; i++) {
    scanf("%d", &L[i]);
  }

  // D: Array to store the coordinate of each bounce
  int D[N + 1];

  // Calculate the coordinates of each bounce
  D[0] = 0;
  for (int i = 1; i <= N; i++) {
    D[i] = D[i - 1] + L[i - 1];
  }

  // Count the number of bounces with a coordinate at most X
  int count = 0;
  for (int i = 0; i <= N; i++) {
    if (D[i] <= X) {
      count++;
    }
  }

  // Print the result
  printf("%d\n", count);

  return 0;
}