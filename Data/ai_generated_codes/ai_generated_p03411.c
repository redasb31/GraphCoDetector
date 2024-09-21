#include <stdio.h>

int main() {
  // N: number of red and blue points
  int N;
  scanf("%d", &N);

  // a[i], b[i]: coordinates of the i-th red point
  int a[100], b[100];
  // c[i], d[i]: coordinates of the i-th blue point
  int c[100], d[100];

  // Read the coordinates of the red points
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &a[i], &b[i]);
  }

  // Read the coordinates of the blue points
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &c[i], &d[i]);
  }

  // Count the maximum number of friendly pairs
  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // Check if the red point is smaller than the blue point in both x and y coordinates
      if (a[i] < c[j] && b[i] < d[j]) {
        // Increment the count of friendly pairs
        count++;
        // Break the inner loop after finding a pair for the current red point
        break;
      }
    }
  }

  // Print the maximum number of friendly pairs
  printf("%d\n", count);

  return 0;
}