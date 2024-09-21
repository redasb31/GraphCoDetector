#include <stdio.h>

// Function to find the lower bound of a value in a sorted array
int lowerBound(int arr[], int n, int key) {
  int left = 0;
  int right = n - 1;
  int result = n; // Initialize result to n, which means the key is not present in the array

  // Perform binary search
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] >= key) {
      result = mid; // Update result if a value greater than or equal to key is found
      right = mid - 1; // Search further in the left half
    } else {
      left = mid + 1; // Search in the right half
    }
  }

  return result;
}

int main() {
  int n, q;
  int arr[100000];

  scanf("%d", &n); // Read the number of elements

  // Read the array elements
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  scanf("%d", &q); // Read the number of queries

  // Process each query
  for (int i = 0; i < q; i++) {
    int key;
    scanf("%d", &key);

    int index = lowerBound(arr, n, key); // Find the lower bound
    printf("%d\n", index); // Print the index
  }

  return 0;
}