#include <stdio.h>

// Function to check if a sum 't' can be made using elements from 'A' after index 'p'
int solve(int p, int t, int A[], int n) {
  // Base case: If the target sum is 0, we've found a solution
  if (t == 0) {
    return 1; 
  }

  // Base case: If we've reached the end of the array or the target sum is negative, no solution
  if (p == n || t < 0) {
    return 0;
  }

  // Try including the current element 'A[p]'
  int include = solve(p + 1, t - A[p], A, n);

  // Try excluding the current element 'A[p]'
  int exclude = solve(p + 1, t, A, n);

  // Return 1 if either including or excluding the element leads to a solution
  return include || exclude;
}

int main() {
  int n, q, A[20], M, i;

  // Read the number of elements in the sequence
  scanf("%d", &n);

  // Read the elements of the sequence
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  // Read the number of queries
  scanf("%d", &q);

  // Read the target sums for each query
  for (i = 0; i < q; i++) {
    scanf("%d", &M);

    // Check if the target sum can be made
    if (solve(0, M, A, n)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}