#include <stdio.h>

// Function to merge two sorted subarrays into one sorted array
// Also counts the number of comparisons made
void Merge(int A[], int left, int mid, int right, int *comparisons) {
  int n1 = mid - left;
  int n2 = right - mid;

  // Create temporary arrays L and R
  int L[n1 + 1], R[n2 + 1];

  // Copy data to temporary arrays
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }

  // Add sentinels to the end of the temporary arrays
  L[n1] = R[n2] = 1000000000; // Assuming all elements in S are ≤ 10^9

  // Initialize indices for L, R, and A
  int i = 0, j = 0, k = left;

  // Merge the subarrays
  while (k < right) {
    (*comparisons)++; // Increment comparisons count
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    k++;
  }
}

// Recursive function to perform Merge Sort
void MergeSort(int A[], int left, int right, int *comparisons) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;

    // Recursively sort the two subarrays
    MergeSort(A, left, mid, comparisons);
    MergeSort(A, mid, right, comparisons);

    // Merge the sorted subarrays
    Merge(A, left, mid, right, comparisons);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int A[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  int comparisons = 0;
  MergeSort(A, 0, n, &comparisons);

  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  printf("%d\n", comparisons);

  return 0;
}