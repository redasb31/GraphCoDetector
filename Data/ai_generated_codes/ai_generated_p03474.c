#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables for A, B, and the postal code string
  int A, B;
  char S[10];

  // Read in the input values
  scanf("%d %d\n", &A, &B);
  scanf("%s", S);

  // Check if the string length is correct
  if (strlen(S) != A + B + 1) {
    printf("No\n");
    return 0;
  }

  // Check if the hyphen is in the correct position
  if (S[A] != '-') {
    printf("No\n");
    return 0;
  }

  // Check if all other characters are digits
  for (int i = 0; i < A + B + 1; i++) {
    if (i == A) {
      continue; // Skip the hyphen
    }
    if (S[i] < '0' || S[i] > '9') {
      printf("No\n");
      return 0;
    }
  }

  // If all checks pass, the postal code is valid
  printf("Yes\n");

  return 0;
}