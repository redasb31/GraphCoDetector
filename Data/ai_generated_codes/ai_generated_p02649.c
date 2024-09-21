#include <stdio.h>

// Function to calculate the number of ways to choose a set of numbers that satisfy the conditions.
int count_sets(int n, int k, int s, int t, int *a) {
  // Initialize the count to 0.
  int count = 0;

  // Iterate over all possible subsets of size 1 to k.
  for (int i = 1; i <= k; i++) {
    // Iterate over all combinations of i numbers from the given array.
    for (int j = 0; j < (1 << n); j++) {
      // Check if the number of set bits in j is equal to i.
      if (__builtin_popcount(j) == i) {
        // Calculate the bitwise AND and OR of the chosen numbers.
        int and_sum = 0, or_sum = 0;
        for (int l = 0; l < n; l++) {
          if (j & (1 << l)) {
            and_sum &= a[l]; // Update the bitwise AND.
            or_sum |= a[l]; // Update the bitwise OR.
          }
        }

        // Check if the bitwise AND and OR match the given values.
        if (and_sum == s && or_sum == t) {
          count++; // Increment the count if the conditions are satisfied.
        }
      }
    }
  }

  return count; // Return the final count.
}

int main() {
  // Read the input values.
  int n, k, s, t;
  scanf("%d %d %d %d", &n, &k, &s, &t);

  // Allocate memory for the array.
  int *a = (int *)malloc(sizeof(int) * n);

  // Read the array elements.
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate and print the number of sets.
  printf("%d\n", count_sets(n, k, s, t, a));

  // Free the allocated memory.
  free(a);

  return 0;
}