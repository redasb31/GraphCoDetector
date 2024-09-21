#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum number of operations to make the array non-decreasing
int minOperations(int *arr, int n) {
  int operations = 0; // Initialize the number of operations to 0

  // Iterate through the array, starting from the second element
  for (int i = 1; i < n; i++) {
    // If the current element is less than the previous element, we need to perform operations
    if (arr[i] < arr[i - 1]) {
      // Calculate the difference between the previous element and the current element
      int diff = arr[i - 1] - arr[i];

      // Add the difference to the total number of operations
      operations += diff;

      // Update the current element to be equal to the previous element
      arr[i] = arr[i - 1];
    }
  }

  // Return the total number of operations
  return operations;
}

int main() {
  int n; // Declare the size of the array
  scanf("%d", &n); // Read the size of the array from the input

  int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory for the array

  // Read the elements of the array from the input
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Calculate the minimum number of operations
  int operations = minOperations(arr, n);

  // Print the minimum number of operations
  printf("%d\n", operations);

  // Free the allocated memory
  free(arr);

  return 0; // Exit the program successfully
}