#include <stdio.h>

int main() {
  int n; // Number of integers
  scanf("%d", &n);

  int a[200]; // Array to store the integers
  int max_operations = 0; // Variable to store the maximum operations

  // Read the integers from input
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Find the minimum number of times each integer can be divided by 2
  for (int i = 0; i < n; i++) {
    int count = 0;
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      count++;
    }
    // Update the maximum operations if the current count is higher
    if (count > max_operations) {
      max_operations = count;
    }
  }

  // Print the maximum number of operations
  printf("%d\n", max_operations);

  return 0;
}