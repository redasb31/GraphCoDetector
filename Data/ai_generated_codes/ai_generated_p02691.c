#include <stdio.h>
#include <stdlib.h>

int main() {
  // Read the number of attendees
  int N;
  scanf("%d", &N);

  // Allocate memory for the heights
  int *A = malloc(N * sizeof(int));

  // Read the heights of each attendee
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Initialize the count of pairs satisfying the condition
  int count = 0;

  // Iterate over all possible pairs of attendees
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      // Calculate the absolute difference of their attendee numbers
      int diff = abs(i - j);

      // Calculate the sum of their heights
      int sum = A[i] + A[j];

      // Check if the absolute difference is equal to the sum of heights
      if (diff == sum) {
        // Increment the count if the condition is satisfied
        count++;
      }
    }
  }

  // Print the number of pairs satisfying the condition
  printf("%d\n", count);

  // Free the memory allocated for the heights
  free(A);

  return 0;
}