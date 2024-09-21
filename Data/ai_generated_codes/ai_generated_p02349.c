#include <stdio.h>

// Function to add x to the elements from index s to t in the array A
void add(int A[], int n, int s, int t, int x) {
  // Update the value at index s
  A[s] += x;
  // Update the value at index t+1 (if t+1 is within the array bounds)
  if (t + 1 <= n) {
    A[t + 1] -= x;
  }
}

// Function to get the value at index i in the array A
int get(int A[], int n, int i) {
  // Calculate the sum of all additions up to index i
  int sum = 0;
  for (int j = 1; j <= i; j++) {
    sum += A[j];
  }
  // Return the sum
  return sum;
}

int main() {
  // Declare variables
  int n, q, query_type, s, t, x, i;
  // Read the size of the array and the number of queries
  scanf("%d %d", &n, &q);

  // Allocate memory for the array A of size n+1
  int A[n + 1];
  // Initialize all elements of A to 0
  for (int i = 0; i <= n; i++) {
    A[i] = 0;
  }

  // Process each query
  for (int j = 0; j < q; j++) {
    // Read the query type, s, t, and x
    scanf("%d", &query_type);
    if (query_type == 0) {
      scanf("%d %d %d", &s, &t, &x);
      // Perform the add operation
      add(A, n, s, t, x);
    } else {
      scanf("%d", &i);
      // Perform the get operation
      printf("%d\n", get(A, n, i));
    }
  }

  return 0;
}