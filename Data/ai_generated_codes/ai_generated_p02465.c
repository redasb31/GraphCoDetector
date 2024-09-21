#include <stdio.h>

int main() {
  // Declare variables for the size of the sets and the elements themselves.
  int n, m;
  int a[200000], b[200000];

  // Read the size of the sets A and B.
  scanf("%d", &n);
  // Read the elements of set A.
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  // Read the size of the set B.
  scanf("%d", &m);
  // Read the elements of set B.
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }

  // Initialize two pointers, one for set A and one for set B.
  int i = 0, j = 0;

  // Iterate through the sets A and B until one of the pointers reaches the end of its set.
  while (i < n && j < m) {
    // If the current element of A is smaller than the current element of B, print it and move the pointer for A forward.
    if (a[i] < b[j]) {
      printf("%d\n", a[i]);
      i++;
    }
    // If the current element of B is smaller than the current element of A, move the pointer for B forward.
    else if (a[i] > b[j]) {
      j++;
    }
    // If the current elements of A and B are equal, move both pointers forward.
    else {
      i++;
      j++;
    }
  }

  // Print the remaining elements of set A, if any.
  while (i < n) {
    printf("%d\n", a[i]);
    i++;
  }

  return 0;
}