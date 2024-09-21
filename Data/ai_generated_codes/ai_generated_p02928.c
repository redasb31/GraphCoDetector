#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the inversion number of an array
long long merge_sort_inversions(int *arr, int *temp, int left, int right) {
  long long inv_count = 0;
  if (left < right) {
    int mid = (left + right) / 2;
    inv_count += merge_sort_inversions(arr, temp, left, mid);
    inv_count += merge_sort_inversions(arr, temp, mid + 1, right);
    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}

// Function to merge two sorted subarrays and count inversions
long long merge(int *arr, int *temp, int left, int mid, int right) {
  int i = left, j = mid, k = left, inv_count = 0;
  while (i <= mid - 1 && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      inv_count += (mid - i);
      inv_count %= MOD; // Modulo operation for large numbers
    }
  }
  while (i <= mid - 1) {
    temp[k++] = arr[i++];
  }
  while (j <= right) {
    temp[k++] = arr[j++];
  }
  for (i = left; i <= right; i++) {
    arr[i] = temp[i];
  }
  return inv_count;
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  int *A = (int *)malloc(N * sizeof(int));
  int *B = (int *)malloc(N * K * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < N; j++) {
      B[i * N + j] = A[j];
    }
  }
  int *temp = (int *)malloc(N * K * sizeof(int));
  long long inversions = merge_sort_inversions(B, temp, 0, N * K - 1);
  printf("%lld\n", inversions);
  free(A);
  free(B);
  free(temp);
  return 0;
}