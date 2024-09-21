#include <stdio.h>
#include <limits.h>

// Function to calculate the maximum value of f(X)
int max_f(int n, int k, int *a) {
  // Initialize the maximum value of f(X) to 0
  int max_val = 0;

  // Iterate over all possible values of X from 0 to K
  for (int x = 0; x <= k; x++) {
    // Calculate f(X) for the current value of X
    int f_x = 0;
    for (int i = 0; i < n; i++) {
      f_x += (x ^ a[i]);
    }

    // Update the maximum value of f(X) if necessary
    if (f_x > max_val) {
      max_val = f_x;
    }
  }

  // Return the maximum value of f(X)
  return max_val;
}

int main() {
  // Number of integers
  int n;
  scanf("%d", &n);

  // Non-negative integer K
  int k;
  scanf("%d", &k);

  // Array of non-negative integers
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate and print the maximum value of f(X)
  printf("%d\n", max_f(n, k, a));

  return 0;
}