#include <stdio.h>

int main() {
  // N: Number of flowers
  int N;
  // h: Array to store the desired heights of flowers
  int h[101];
  // operations: Number of watering operations required
  int operations = 0;

  // Read the number of flowers
  scanf("%d", &N);

  // Read the desired heights of flowers
  for (int i = 1; i <= N; i++) {
    scanf("%d", &h[i]);
  }

  // Iterate through all flowers
  for (int i = 1; i <= N; i++) {
    // If the current flower's height is less than its desired height
    if (h[i] > 0) {
      // Perform watering operations until the height reaches the desired height
      while (h[i] > 0) {
        // Increase the height of all flowers from the current flower to the last flower
        for (int j = i; j <= N; j++) {
          h[j]--;
        }
        // Increment the number of operations
        operations++;
      }
    }
  }

  // Print the minimum number of watering operations
  printf("%d\n", operations);

  return 0;
}