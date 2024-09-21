#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input variables
  int X, Y, Z, A, B, C, N;

  // Scan input
  scanf("%d %d %d %d %d %d %d", &X, &Y, &Z, &A, &B, &C, &N);

  // Array to store the count of each color
  int color_count[1001] = {0}; 

  // Iterate through all the cubes
  for (int x = 0; x < X; x++) {
    for (int y = 0; y < Y; y++) {
      for (int z = 0; z < Z; z++) {
        // Calculate Manhattan distance
        int distance = abs(x - A) + abs(y - B) + abs(z - C);

        // Determine color based on distance and N
        int color = (distance % N) + 1; 

        // Increment the count of the corresponding color
        color_count[color]++;
      }
    }
  }

  // Print the count of each color
  for (int i = 1; i <= N; i++) {
    printf("%d ", color_count[i]);
  }
  printf("\n");

  return 0;
}