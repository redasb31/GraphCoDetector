#include <stdio.h>

int main() {
  // Declare variables for K, A, and B
  int K, A, B;

  // Read input values from the user
  scanf("%d", &K);
  scanf("%d %d", &A, &B);

  // Check if any multiple of K lies between A and B
  for (int i = A; i <= B; i++) {
    // Check if the current number is a multiple of K
    if (i % K == 0) {
      // If a multiple of K is found, print OK and exit the loop
      printf("OK\n");
      return 0;
    }
  }

  // If no multiple of K is found, print NG
  printf("NG\n");

  return 0;
}