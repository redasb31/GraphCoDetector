#include <stdio.h>

// Function to find the lower bound (first element greater than or equal to k)
int lower_bound(int arr[], int n, int k) {
  int left = 0;
  int right = n; // We include n in the search space

  while (left < right) {
    int mid = left + (right - left) / 2; // Calculate midpoint

    if (arr[mid] >= k) {
      right = mid; // Narrow down the search space to the left half
    } else {
      left = mid + 1; // Narrow down the search space to the right half
    }
  }

  return left; // Return the index of the lower bound
}

// Function to find the upper bound (first element greater than k)
int upper_bound(int arr[], int n, int k) {
  int left = 0;
  int right = n; // We include n in the search space

  while (left < right) {
    int mid = left + (right - left) / 2; // Calculate midpoint

    if (arr[mid] > k) {
      right = mid; // Narrow down the search space to the left half
    } else {
      left = mid + 1; // Narrow down the search space to the right half
    }
  }

  return left; // Return the index of the upper bound
}

int main() {
  int n, q, k;
  scanf("%d", &n); // Read the number of elements

  int arr[100000]; // Array to store the elements

  // Read the elements of the array
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  scanf("%d", &q); // Read the number of queries

  // Process each query
  for (int i = 0; i < q; i++) {
    scanf("%d", &k); // Read the query value

    // Find the lower and upper bounds
    int lower = lower_bound(arr, n, k);
    int upper = upper_bound(arr, n, k);

    // Print the results
    printf("%d %d\n", lower, upper);
  }

  return 0;
}