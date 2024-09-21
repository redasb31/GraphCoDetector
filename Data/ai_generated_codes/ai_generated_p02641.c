#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input the target number and the length of the sequence.
  int X, N;
  scanf("%d %d", &X, &N);

  // Create an array to store the sequence of numbers.
  int *p = malloc(N * sizeof(int));

  // Input the sequence of numbers.
  for (int i = 0; i < N; i++) {
    scanf("%d", &p[i]);
  }

  // Initialize the closest number and its difference with the target.
  int closest = X;
  int minDiff = abs(X - closest);

  // Loop through all possible numbers from 1 to 100.
  for (int i = 1; i <= 100; i++) {
    // Check if the current number is in the sequence.
    int found = 0;
    for (int j = 0; j < N; j++) {
      if (p[j] == i) {
        found = 1;
        break;
      }
    }

    // If the current number is not in the sequence, calculate its difference with the target.
    if (!found) {
      int diff = abs(X - i);
      // Update the closest number if the difference is smaller or the difference is equal and the current number is smaller.
      if (diff < minDiff || (diff == minDiff && i < closest)) {
        closest = i;
        minDiff = diff;
      }
    }
  }

  // Print the closest number.
  printf("%d\n", closest);

  // Free the allocated memory.
  free(p);

  return 0;
}