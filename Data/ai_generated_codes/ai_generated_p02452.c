#include <stdio.h>

int main() {
  // n: number of elements in A
  // m: number of elements in B
  int n, m;

  // Read the number of elements in A
  scanf("%d", &n);

  // Declare an array A to store elements of A
  int A[n];

  // Read the elements of A
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  // Read the number of elements in B
  scanf("%d", &m);

  // Declare an array B to store elements of B
  int B[m];

  // Read the elements of B
  for (int i = 0; i < m; i++) {
    scanf("%d", &B[i]);
  }

  // Initialize a pointer to the beginning of A
  int j = 0;

  // Iterate through all elements of B
  for (int i = 0; i < m; i++) {
    // While j < n and A[j] < B[i] keep increasing j
    while (j < n && A[j] < B[i]) {
      j++;
    }
    // If j == n (i.e., we reached the end of A) or A[j] != B[i] then B[i] is not found in A
    if (j == n || A[j] != B[i]) {
      printf("0\n");
      return 0;
    }
  }
  // If all elements of B are found in A then print 1
  printf("1\n");

  return 0;
}