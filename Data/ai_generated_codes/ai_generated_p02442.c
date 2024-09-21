#include <stdio.h>

int main() {
  // Declare variables for the lengths of the sequences and the sequences themselves.
  int n, m;
  int a[1000], b[1000];

  // Read the length of the first sequence.
  scanf("%d", &n);

  // Read the elements of the first sequence.
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Read the length of the second sequence.
  scanf("%d", &m);

  // Read the elements of the second sequence.
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }

  // Compare the sequences lexicographically.
  // Iterate through both sequences simultaneously until the end of one sequence is reached or a difference is found.
  int i;
  for (i = 0; i < n && i < m; i++) {
    if (a[i] > b[i]) {
      // If an element in A is greater than the corresponding element in B, then B is lexicographically greater than A.
      printf("1\n");
      return 0;
    } else if (a[i] < b[i]) {
      // If an element in A is less than the corresponding element in B, then B is not lexicographically greater than A.
      printf("0\n");
      return 0;
    }
  }

  // If the end of one sequence is reached without finding a difference, then the sequence with fewer elements is lexicographically smaller.
  if (i == n) {
    // If A is shorter than B, then B is lexicographically greater than A.
    printf("1\n");
  } else {
    // If B is shorter than A, then B is not lexicographically greater than A.
    printf("0\n");
  }

  return 0;
}