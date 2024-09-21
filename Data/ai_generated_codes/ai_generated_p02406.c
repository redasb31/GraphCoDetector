#include <stdio.h>

int main() {
  int n, i = 1, x; // Initialize variables

  // Input for n
  scanf("%d", &n);

  // Loop to mimic the 'goto' behavior
  while (i <= n) {
    x = i; 

    // Check for divisibility by 3
    if (x % 3 == 0) {
      printf(" %d", i);
      i++; // Increment i for the next iteration
      continue; // Skip to the next iteration
    }

    // Check for divisibility by 9
    while (x % 9 == 0) {
      printf(" %d", i);
      x /= 9; // Divide x by 9
    }

    // Check for divisibility by 3 and 9 (excluding multiples of 9)
    if (x % 3 == 0) {
      printf(" %d", i);
    }

    // Increment i for the next iteration
    i++;
  }

  printf("\n"); // Print a newline at the end

  return 0;
}