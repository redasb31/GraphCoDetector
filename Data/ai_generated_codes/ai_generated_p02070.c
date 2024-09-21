#include <stdio.h>
#include <stdlib.h>

// Function to check if the given permutation is sorted in increasing order
int is_sorted(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] > arr[i]) {
      return 0; // Not sorted
    }
  }
  return 1; // Sorted
}

// Function to simulate the permutation operation for a single day
void apply_permutation(int *arr, int *q, int n) {
  int temp[n];
  for (int i = 0; i < n; i++) {
    temp[i] = q[arr[i] - 1]; // Apply the permutation Q
  }
  for (int i = 0; i < n; i++) {
    arr[i] = temp[i];
  }
}

int main() {
  int n, *p, *q;
  scanf("%d", &n);

  // Allocate memory for the permutations
  p = (int *)malloc(n * sizeof(int));
  q = (int *)malloc(n * sizeof(int));

  // Read the input permutations
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &q[i]);
  }

  // Simulate the permutation process for at most 10^18 days
  long long d = 0;
  for (; d <= 1000000000000000000; d++) {
    if (is_sorted(p, n)) {
      break; // Permutation is sorted
    }
    apply_permutation(p, q, n); // Apply permutation for the day
  }

  // Check if the permutation was sorted
  if (is_sorted(p, n)) {
    printf("%lld\n", d); // Print the minimum day
  } else {
    printf("-1\n"); // Permutation never gets sorted
  }

  free(p); // Free allocated memory
  free(q);

  return 0;
}