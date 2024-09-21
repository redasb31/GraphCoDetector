#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, *a, *balls, count, i, j, good_set = 1;

  // Get the number of boxes
  scanf("%d", &N);

  // Allocate memory for the array of constraints and the array of balls
  a = (int *)malloc(sizeof(int) * N);
  balls = (int *)malloc(sizeof(int) * N);

  // Read the constraints from the input
  for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Initialize the array of balls to 0
  for (i = 0; i < N; i++) {
    balls[i] = 0;
  }

  // Iterate through each box to check if a good set of choices exists
  for (i = 1; i <= N; i++) {
    count = 0;

    // Check for multiples of i
    for (j = i - 1; j < N; j += i) {
      // Increment the count of balls if a multiple of i has a ball
      if (balls[j]) {
        count++;
      }
    }

    // If the count is not congruent to the constraint modulo 2, then there is no good set
    if (count % 2 != a[i - 1]) {
      good_set = 0;
      break;
    }
  }

  // If a good set of choices exists, print the choices
  if (good_set) {
    count = 0;
    // Iterate through the array of balls to count the balls
    for (i = 0; i < N; i++) {
      if (balls[i]) {
        count++;
      }
    }

    // Print the number of balls
    printf("%d\n", count);

    // Print the indices of the boxes with balls
    for (i = 0; i < N; i++) {
      if (balls[i]) {
        printf("%d ", i + 1);
      }
    }
    printf("\n");
  } else {
    printf("-1\n");
  }

  // Free the allocated memory
  free(a);
  free(balls);

  return 0;
}