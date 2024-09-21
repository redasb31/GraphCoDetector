#include <stdio.h>
#include <stdlib.h>

int main() {
  int n; // Number of cards
  scanf("%d", &n);

  int *a = malloc(sizeof(int) * n); // Array to store the numbers on the cards

  // Read the numbers on the cards
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Create an array to store the count of each number
  int *count = calloc(n + 1, sizeof(int));
  for (int i = 0; i < n; i++) {
    count[a[i]]++;
  }

  // Calculate the maximum number of operations for each K
  for (int k = 1; k <= n; k++) {
    int max_operations = 0;
    int current_operations = 0;

    // Iterate through the numbers on the cards
    for (int i = 1; i <= n; i++) {
      // If the current number appears at least K times
      if (count[i] >= k) {
        // Increase the current number of operations
        current_operations++;
        // Decrease the count of the current number by K
        count[i] -= k;
      }
      // If the current number appears less than K times
      else {
        // Reset the current number of operations to 0
        current_operations = 0;
      }

      // Update the maximum number of operations
      max_operations = (max_operations > current_operations) ? max_operations : current_operations;
    }

    // Print the maximum number of operations for the current K
    printf("%d ", max_operations);
  }

  // Free the allocated memory
  free(a);
  free(count);

  return 0;
}