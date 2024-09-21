#include <stdio.h>

int main() {
  int N; // Number of red and blue points
  scanf("%d", &N);

  // Store the coordinates of red and blue points
  int a[100], b[100], c[100], d[100];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &a[i], &b[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &c[i], &d[i]);
  }

  // Sort the red points based on their x-coordinates
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (a[i] > a[j]) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        temp = b[i];
        b[i] = b[j];
        b[j] = temp;
      }
    }
  }

  // Sort the blue points based on their x-coordinates
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (c[i] > c[j]) {
        int temp = c[i];
        c[i] = c[j];
        c[j] = temp;
        temp = d[i];
        d[i] = d[j];
        d[j] = temp;
      }
    }
  }

  // Initialize count of friendly pairs
  int count = 0;
  int i = 0, j = 0;

  // Greedily form friendly pairs
  while (i < N && j < N) {
    // If the x-coordinate of the current red point is less than that of the current blue point
    // and the y-coordinate of the current red point is less than that of the current blue point
    // then form a friendly pair and move to the next red point
    if (a[i] < c[j] && b[i] < d[j]) {
      count++;
      i++;
    } else {
      // Otherwise, move to the next blue point
      j++;
    }
  }

  // Print the maximum number of friendly pairs
  printf("%d\n", count);

  return 0;
}