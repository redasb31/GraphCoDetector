#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int a[51];
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  // Track the operations performed
  int operations = 0;
  // Iterate over the array from right to left
  for (int i = n; i > 1; --i) {
    // If the current element is less than the previous element
    if (a[i] < a[i - 1]) {
      // Add the difference to the current element
      a[i] += (a[i - 1] - a[i]);
      // Increment the operation count
      operations++;
      // Print the operation
      printf("%d %d\n", i - 1, i);
    }
  }

  // Print the total number of operations
  printf("%d\n", operations);

  return 0;
}