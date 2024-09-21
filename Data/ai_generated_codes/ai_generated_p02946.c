#include <stdio.h>

int main() {
  // K: Number of consecutive black stones
  int K; 
  // X: Coordinate of the known black stone
  int X;

  // Read input
  scanf("%d %d", &K, &X);

  // Print the potential black stone coordinates
  for (int i = X - (K - 1); i <= X + (K - 1); i++) {
    printf("%d ", i);
  }

  return 0;
}