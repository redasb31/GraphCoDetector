#include <stdio.h>

int main() {
  // Declare variables for the sizes of sets A and B.
  int n, m;

  // Read the size of set A.
  scanf("%d", &n);

  // Declare an array to store the elements of set A.
  int a[n];

  // Read the elements of set A.
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Read the size of set B.
  scanf("%d", &m);

  // Declare an array to store the elements of set B.
  int b[m];

  // Read the elements of set B.
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }

  // Initialize pointers for iterating through sets A and B.
  int i = 0, j = 0;

  // Iterate through both sets and compare elements.
  while (i < n && j < m) {
    // If the current element in set A is smaller than the current element in set B, move the pointer for set A forward.
    if (a[i] < b[j]) {
      i++;
    } 
    // If the current element in set B is smaller than the current element in set A, move the pointer for set B forward.
    else if (a[i] > b[j]) {
      j++;
    }
    // If the elements are equal, print the element as it's in the intersection and move both pointers forward.
    else {
      printf("%d\n", a[i]);
      i++;
      j++;
    }
  }

  return 0;
}