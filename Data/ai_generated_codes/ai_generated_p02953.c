#include <stdio.h>

int main() {
  int N; // Number of squares
  scanf("%d", &N);

  int H[100000]; // Array to store heights of squares
  for (int i = 0; i < N; i++) {
    scanf("%d", &H[i]);
  }

  // Check if it's possible to make heights non-decreasing
  int is_possible = 1; // Assume it's possible initially
  for (int i = 1; i < N; i++) {
    // If the current height is less than the previous height,
    // we need to decrease the current height
    if (H[i] < H[i - 1]) {
      // If the difference is more than 1, it's not possible
      if (H[i - 1] - H[i] > 1) {
        is_possible = 0; // Not possible
        break; // Exit the loop as it's already not possible
      }
      // Otherwise, we can decrease the current height by 1
      H[i]++;
    }
  }

  // Print the result
  if (is_possible) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}