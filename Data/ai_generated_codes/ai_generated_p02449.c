#include <stdio.h>

// Function to find the previous permutation in lexicographic order
void prevPermutation(int arr[], int n) {
  // Find the largest index i such that arr[i] > arr[i-1]
  int i = n - 1;
  while (i > 0 && arr[i] <= arr[i - 1]) {
    i--;
  }

  // If no such index exists, then the given sequence is the smallest permutation
  if (i == 0) {
    return;
  }

  // Find the largest index j such that arr[j] < arr[i-1]
  int j = n - 1;
  while (arr[j] >= arr[i - 1]) {
    j--;
  }

  // Swap arr[i-1] and arr[j]
  int temp = arr[i - 1];
  arr[i - 1] = arr[j];
  arr[j] = temp;

  // Reverse the subsequence from index i to the end
  int k = i;
  int l = n - 1;
  while (k < l) {
    temp = arr[k];
    arr[k] = arr[l];
    arr[l] = temp;
    k++;
    l--;
  }

  // Print the previous permutation
  for (int k = 0; k < n; k++) {
    printf("%d ", arr[k]);
  }
  printf("\n");
}

// Function to find the next permutation in lexicographic order
void nextPermutation(int arr[], int n) {
  // Find the largest index i such that arr[i] < arr[i+1]
  int i = n - 2;
  while (i >= 0 && arr[i] >= arr[i + 1]) {
    i--;
  }

  // If no such index exists, then the given sequence is the largest permutation
  if (i < 0) {
    return;
  }

  // Find the smallest index j such that arr[j] > arr[i]
  int j = n - 1;
  while (arr[j] <= arr[i]) {
    j--;
  }

  // Swap arr[i] and arr[j]
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;

  // Reverse the subsequence from index i+1 to the end
  int k = i + 1;
  int l = n - 1;
  while (k < l) {
    temp = arr[k];
    arr[k] = arr[l];
    arr[l] = temp;
    k++;
    l--;
  }

  // Print the next permutation
  for (int k = 0; k < n; k++) {
    printf("%d ", arr[k]);
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Print the previous permutation
  prevPermutation(arr, n);

  // Print the given sequence
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Print the next permutation
  nextPermutation(arr, n);

  return 0;
}