#include <stdio.h>
#include <stdlib.h>

// Function to check if two binary numbers differ by exactly one bit
int check_diff(int a, int b) {
  int count = 0;
  int diff = a ^ b; // Bitwise XOR to find the bits that differ
  while (diff) {
    count++;
    diff &= (diff - 1); // Clear the rightmost set bit
  }
  return (count == 1); // Return true if only one bit differs
}

// Function to generate a permutation satisfying the conditions
void generate_permutation(int N, int A, int B, int *perm) {
  // Initialize the permutation array
  perm[0] = A;
  perm[1 << N] = B;

  // Generate the permutation in a bitwise fashion
  for (int i = 1; i < (1 << N); i++) {
    int prev = perm[i - 1];
    int next = perm[i + 1];

    // Find the bit to change to move from prev to next
    int diff = prev ^ next;
    int bit_pos = 0;
    while (!(diff & (1 << bit_pos))) {
      bit_pos++;
    }

    // Change the bit in prev to get to the current element
    perm[i] = prev ^ (1 << bit_pos);
  }
}

int main() {
  int N, A, B;
  scanf("%d %d %d", &N, &A, &B);

  int *perm = malloc((1 << N) * sizeof(int));

  // Check if A and B differ by exactly one bit
  if (!check_diff(A, B)) {
    printf("NO\n");
    free(perm);
    return 0;
  }

  // Generate the permutation
  generate_permutation(N, A, B, perm);

  // Print the permutation
  printf("YES\n");
  for (int i = 0; i < (1 << N); i++) {
    if (i > 0) {
      printf(" ");
    }
    printf("%d", perm[i]);
  }
  printf("\n");

  free(perm);
  return 0;
}