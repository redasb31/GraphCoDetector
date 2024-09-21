#include <stdio.h>

int main() {
  // Declare variables to store the incorrect choices.
  int A, B;

  // Read the incorrect choices from the input.
  scanf("%d\n%d", &A, &B);

  // Determine the correct choice by checking all possible combinations of incorrect choices.
  if (A == 1 && B == 2) {
    printf("3\n"); // If A is 1 and B is 2, then the correct choice is 3.
  } else if (A == 1 && B == 3) {
    printf("2\n"); // If A is 1 and B is 3, then the correct choice is 2.
  } else if (A == 2 && B == 1) {
    printf("3\n"); // If A is 2 and B is 1, then the correct choice is 3.
  } else if (A == 2 && B == 3) {
    printf("1\n"); // If A is 2 and B is 3, then the correct choice is 1.
  } else if (A == 3 && B == 1) {
    printf("2\n"); // If A is 3 and B is 1, then the correct choice is 2.
  } else if (A == 3 && B == 2) {
    printf("1\n"); // If A is 3 and B is 2, then the correct choice is 1.
  }

  return 0;
}