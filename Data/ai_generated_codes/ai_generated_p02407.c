#include <stdio.h>

int main() {
  // Declare variables for the number of elements and the array
  int n, i;
  int arr[100]; // Array to store the sequence

  // Read the number of elements
  scanf("%d", &n);

  // Read the sequence of numbers
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Print the sequence in reverse order
  for (i = n - 1; i >= 0; i--) {
    printf("%d", arr[i]);
    if (i > 0) {
      printf(" "); // Print space between elements, except for the last one
    }
  }
  printf("\n"); // Print a newline at the end
  return 0;
}