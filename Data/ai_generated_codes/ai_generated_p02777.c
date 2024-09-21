#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables for the strings and the number of balls
  char S[11], T[11], U[11];
  int A, B;

  // Read the input strings and the number of balls
  scanf("%s %s\n", S, T);
  scanf("%d %d\n", &A, &B);
  scanf("%s", U);

  // Check if the chosen ball has the string S or T
  if (strcmp(S, U) == 0) {
    // If the chosen ball has the string S, decrement the number of balls with S
    A--;
  } else {
    // If the chosen ball has the string T, decrement the number of balls with T
    B--;
  }

  // Print the number of balls with S and T
  printf("%d %d\n", A, B);

  return 0;
}