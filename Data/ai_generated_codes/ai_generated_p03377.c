#include <stdio.h>

int main() {
  int A, B, X; // Declare variables for cats, unknown animals, and desired cats

  // Get input from the user
  scanf("%d %d %d", &A, &B, &X); 

  // Check if it's possible to have X cats
  if (A <= X && X <= (A + B)) { // If the desired number of cats is within the possible range
    printf("YES\n"); // Print YES
  } else {
    printf("NO\n"); // Print NO
  }

  return 0;
}