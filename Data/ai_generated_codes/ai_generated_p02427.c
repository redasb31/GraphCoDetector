#include <stdio.h>

int main() {
  // n: number of elements in the set
  int n;
  scanf("%d", &n);

  // Iterate through all possible subsets, represented as integers from 0 to 2^n - 1
  for (int i = 0; i < (1 << n); i++) {
    // d: decimal representation of the subset
    int d = i;
    printf("%d:", d);

    // Flag to indicate if any element is present in the subset
    int hasElement = 0;

    // Iterate through each element in the set
    for (int j = 0; j < n; j++) {
      // Check if the j-th bit is set in the subset
      if (i & (1 << j)) {
        // Print the element if present
        printf(" %d", j);
        hasElement = 1;
      }
    }

    // If the subset is not empty, print a space character after ':'
    if (hasElement) {
      printf(" ");
    }

    // Print a newline for each subset
    printf("\n");
  }

  return 0;
}