#include <stdio.h>
#include <stdlib.h>

int main() {
  // Get the number of frames
  int N;
  scanf("%d", &N);

  // Allocate memory for the frame representations
  int *a = (int *)malloc(sizeof(int) * N);

  // Read the frame representations
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate the average of the frame representations
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += a[i];
  }
  double average = (double)sum / N;

  // Find the index of the frame with the representation closest to the average
  int min_index = 0;
  double min_distance = abs(a[0] - average);
  for (int i = 1; i < N; i++) {
    double distance = abs(a[i] - average);
    if (distance < min_distance) {
      min_distance = distance;
      min_index = i;
    } else if (distance == min_distance && i < min_index) {
      min_index = i;
    }
  }

  // Print the index
  printf("%d\n", min_index);

  // Free the allocated memory
  free(a);

  return 0;
}