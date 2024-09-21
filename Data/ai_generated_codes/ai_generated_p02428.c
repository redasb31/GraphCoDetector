#include <stdio.h>

// Function to print a subset
void printSubset(int n, int subset) {
  printf("%d: ", subset);
  for (int i = 0; i < n; i++) {
    if (subset & (1 << i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

// Function to enumerate all subsets containing T
void enumerateSubsets(int n, int k, int *T) {
  // Calculate the integer representation of T
  int T_int = 0;
  for (int i = 0; i < k; i++) {
    T_int |= (1 << T[i]);
  }

  // Iterate through all possible subsets
  for (int subset = T_int; subset < (1 << n); subset++) {
    // Check if the current subset contains T
    if ((subset & T_int) == T_int) {
      printSubset(n, subset);
    }
  }
}

int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);

  // Read the elements of T
  int T[k];
  for (int i = 0; i < k; i++) {
    scanf("%d", &T[i]);
  }

  // Enumerate all subsets containing T
  enumerateSubsets(n, k, T);

  return 0;
}