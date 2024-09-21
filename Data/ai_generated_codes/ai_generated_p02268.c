#include <stdio.h>

int main() {
  // n: number of elements in S
  // q: number of elements in T
  int n, q, i, j, c = 0;

  // Read the number of elements in S
  scanf("%d", &n);

  // Declare an array S to store the elements of S
  int S[n];

  // Read the elements of S
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  // Read the number of elements in T
  scanf("%d", &q);

  // Declare an array T to store the elements of T
  int T[q];

  // Read the elements of T
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }

  // Iterate over each element in T
  for (i = 0; i < q; i++) {
    // Perform binary search to check if the current element in T is present in S
    // j is the index of the element in S if found, otherwise j is the index where the element should be inserted
    j = binary_search(S, 0, n - 1, T[i]);

    // If the element is found in S, increment the count
    if (j != -1) {
      c++;
    }
  }

  // Print the count of elements in T that are also in S
  printf("%d\n", c);

  return 0;
}

// Binary search function to find an element in a sorted array
int binary_search(int arr[], int left, int right, int x) {
  while (left <= right) {
    int mid = left + (right - left) / 2;

    // If the element is found, return the index
    if (arr[mid] == x) {
      return mid;
    }

    // If the element is smaller than the middle element, search in the left half
    if (arr[mid] > x) {
      right = mid - 1;
    } else {
      // If the element is greater than the middle element, search in the right half
      left = mid + 1;
    }
  }

  // If the element is not found, return -1
  return -1;
}