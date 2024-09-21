#include <stdio.h>

// Function to generate all permutations of the array in lexicographic order
void permute(int n, int *a) {
  int i, j, k;
  // Base case: if n is 1, print the array
  if (n == 1) {
    for (i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
    return;
  }

  // Recursively generate permutations for smaller n
  for (i = 0; i < n; i++) {
    permute(n - 1, a);
    // Swap the last element with the current element
    if (n % 2 == 0) {
      j = i;
      k = n - 1;
    } else {
      j = 0;
      k = i;
    }
    int temp = a[j];
    a[j] = a[k];
    a[k] = temp;
  }
}

int main() {
  int n;
  // Read the input integer n
  scanf("%d", &n);
  // Create an array of size n
  int a[n];
  // Initialize the array with values from 1 to n
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  // Generate and print all permutations
  permute(n, a);
  return 0;
}