#include <stdio.h>
#include <stdlib.h>

// Function to calculate the XOR of two integers
int xor(int a, int b) {
  return a ^ b;
}

int main() {
  int N; // Size of the sequences
  scanf("%d", &N);

  // Allocate memory for the sequences a and b
  int *a = (int *)malloc(N * sizeof(int));
  int *b = (int *)malloc(N * sizeof(int));

  // Read the sequences from the input
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }

  // Flag to track if any pairs are found
  int found = 0;

  // Iterate over all possible values of k
  for (int k = 0; k < N; k++) {
    // Calculate the initial value of x required for a'[0] to be equal to b[0]
    int x = xor(a[0], b[0]) ^ (k * N);

    // Check if the initial value of x satisfies the condition for all elements of the sequence
    int valid = 1;
    for (int i = 1; i < N; i++) {
      if (xor(a[i], b[i]) ^ (k * N) != x) {
        valid = 0;
        break;
      }
    }

    // If the initial value of x is valid, print the pair (k, x)
    if (valid) {
      found = 1;
      printf("%d %d\n", k, x);
    }
  }

  // If no pairs are found, print "No pairs may satisfy the condition."
  if (!found) {
    printf("No pairs may satisfy the condition.\n");
  }

  // Free allocated memory
  free(a);
  free(b);

  return 0;
}