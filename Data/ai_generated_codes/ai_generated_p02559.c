#include <stdio.h>

// Function to perform the update operation on the array
void update(int *arr, int p, int x, int N) {
  // Update the element at index p by adding x to it
  arr[p] += x;
}

// Function to calculate the sum of elements from index l to r-1
int query(int *arr, int l, int r) {
  // Initialize sum to 0
  int sum = 0;
  // Iterate through the elements from index l to r-1 and add them to the sum
  for (int i = l; i < r; i++) {
    sum += arr[i];
  }
  // Return the calculated sum
  return sum;
}

int main() {
  // Declare variables to store the length of the array and the number of queries
  int N, Q;
  // Read the values of N and Q from the input
  scanf("%d %d", &N, &Q);

  // Declare an array of size N to store the elements
  int arr[N];

  // Read the elements of the array from the input
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  // Process each query
  for (int i = 0; i < Q; i++) {
    // Declare variables to store the query type, index p, value x, left index l, and right index r
    int type, p, x, l, r;
    // Read the query type from the input
    scanf("%d", &type);

    // Process the query based on its type
    if (type == 0) {
      // Read the index p and value x from the input
      scanf("%d %d", &p, &x);
      // Update the element at index p
      update(arr, p, x, N);
    } else if (type == 1) {
      // Read the left index l and right index r from the input
      scanf("%d %d", &l, &r);
      // Calculate and print the sum of elements from index l to r-1
      printf("%d\n", query(arr, l, r));
    }
  }

  return 0;
}