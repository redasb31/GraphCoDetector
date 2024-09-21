#include <stdio.h>

int main() {
  // Declare variables for the number of elements and the array.
  int n;
  scanf("%d", &n);

  int a[n];
  // Read the elements of the array.
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Print the first element.
  printf("%d ", a[0]);

  // Iterate through the array, printing only unique elements.
  for (int i = 1; i < n; i++) {
    // If the current element is different from the previous element, print it.
    if (a[i] != a[i - 1]) {
      printf("%d ", a[i]);
    }
  }

  // Print a newline character at the end of the output.
  printf("\n");

  return 0;
}