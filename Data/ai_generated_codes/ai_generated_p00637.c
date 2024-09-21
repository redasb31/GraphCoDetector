#include <stdio.h>

int main() {
  int n, i, prev, current;

  // Loop through datasets until n is 0
  while (scanf("%d", &n) && n != 0) {
    // Read the first page number
    scanf("%d", &prev);

    // Print the first page number
    printf("%d", prev);

    // Loop through the remaining page numbers
    for (i = 1; i < n; i++) {
      scanf("%d", &current);

      // Check if the current page number is consecutive to the previous one
      if (current == prev + 1) {
        // If consecutive, continue printing the range
        prev = current;
      } else {
        // If not consecutive, print the range and the current page number
        if (prev != current - 1) {
          printf("-%d", prev);
        }
        printf(" %d", current);
        prev = current;
      }
    }

    // Print the last range if needed
    if (prev != current - 1) {
      printf("-%d", prev);
    }

    // Print a newline for each dataset
    printf("\n");
  }

  return 0;
}