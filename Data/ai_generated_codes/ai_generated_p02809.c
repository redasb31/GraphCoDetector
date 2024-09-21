#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  scanf("%d", &N);

  // Array to store the conditions
  int *a = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Array to store the arrangement
  int *b = (int *)malloc(sizeof(int) * N);

  // Initialize the arrangement
  for (int i = 0; i < N; i++) {
    b[i] = i + 1;
  }

  // Check if the arrangement is valid
  int valid = 1;
  for (int i = 0; i < N - 1; i++) {
    if (b[i + 1] == a[i]) {
      valid = 0;
      break;
    }
  }

  // If the arrangement is not valid, try to find a valid arrangement
  if (!valid) {
    // Iterate through the arrangement
    for (int i = 0; i < N - 1; i++) {
      // If the current card is not allowed to be next to the next card, swap them
      if (b[i + 1] == a[i]) {
        // Swap the current card and the next card
        int temp = b[i];
        b[i] = b[i + 1];
        b[i + 1] = temp;
        // Check if the arrangement is now valid
        valid = 1;
        for (int j = 0; j < N - 1; j++) {
          if (b[j + 1] == a[j]) {
            valid = 0;
            break;
          }
        }
        // If the arrangement is now valid, break the loop
        if (valid) {
          break;
        }
      }
    }
  }

  // If no valid arrangement is found, print -1
  if (!valid) {
    printf("-1\n");
  } else {
    // Print the lexicographically smallest arrangement
    for (int i = 0; i < N; i++) {
      printf("%d ", b[i]);
    }
    printf("\n");
  }

  free(a);
  free(b);
  return 0;
}