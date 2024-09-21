#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int k) {
  // While left index is less than or equal to right index
  while (left <= right) {
    // Calculate the middle index
    int mid = left + (right - left) / 2;
    // If the element at the middle index is equal to k
    if (arr[mid] == k) {
      return 1; // Return 1 to indicate found
    }
    // If the element at the middle index is less than k
    else if (arr[mid] < k) {
      left = mid + 1; // Search in the right half
    }
    // Otherwise, if the element at the middle index is greater than k
    else {
      right = mid - 1; // Search in the left half
    }
  }
  return 0; // Return 0 to indicate not found
}

int main() {
  int n, q, i, k;
  scanf("%d", &n); // Read the number of elements

  int arr[n]; // Declare an array to store the elements
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]); // Read the elements of the array
  }

  scanf("%d", &q); // Read the number of queries

  // Loop for each query
  for (i = 0; i < q; i++) {
    scanf("%d", &k); // Read the query value
    // Perform binary search and print the result
    printf("%d\n", binarySearch(arr, 0, n - 1, k));
  }
  return 0;
}