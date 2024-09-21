#include <stdio.h>

int main() {
  int N, A, B; // N: number of cells, A: Alice's starting cell, B: Borys's starting cell

  // Input
  scanf("%d %d %d", &N, &A, &B);

  // Check if Alice can make the first move
  if (A == 1 || A == N) {
    printf("Borys\n"); // Alice loses if she's at the edge
  } else {
    // Determine the winner based on the difference between A and B
    if ((B - A) % 2 == 0) { // Even difference: Alice wins
      printf("Alice\n");
    } else { // Odd difference: Borys wins
      printf("Borys\n");
    }
  }

  return 0;
}