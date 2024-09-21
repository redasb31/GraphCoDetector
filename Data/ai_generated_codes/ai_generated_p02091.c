#include <stdio.h>
#include <stdlib.h>

// Function to check if a given set of integers satisfies the conditions
int check_set(int N, int X, int A, int O, int *S) {
  int i, j;
  for (i = 0; i < (1 << N); i++) {
    for (j = 0; j < (1 << N); j++) {
      // Check if the XOR, AND, or OR conditions are violated
      if ((S[i] ^ S[j]) == X || (S[i] & S[j]) == A || (S[i] | S[j]) == O) {
        return 0; // Set does not satisfy the conditions
      }
    }
  }
  return 1; // Set satisfies the conditions
}

int main() {
  int N, X, A, O, i, *S;
  scanf("%d %d %d %d", &N, &X, &A, &O);

  // Allocate memory for the set of integers
  S = (int *)malloc(sizeof(int) * (1 << N));

  // Generate a set of integers and check if it satisfies the conditions
  for (i = 0; i < (1 << N); i++) {
    S[i] = i; // Assign i to the i-th element of the set
    if (check_set(N, X, A, O, S)) {
      printf("Yes\n");
      for (i = 0; i < (1 << N); i++) {
        printf("%d ", S[i]);
      }
      printf("\n");
      free(S);
      return 0; // Found a valid set and exit
    }
  }

  // No valid set found
  printf("No\n");
  free(S);
  return 0;
}