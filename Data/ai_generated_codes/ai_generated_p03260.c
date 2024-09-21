#include <stdio.h>

int main() {
  // Declare variables to store the input values
  int A, B;

  // Read the input values
  scanf("%d %d", &A, &B);

  // Check if either A or B is odd
  if (A % 2 == 1 || B % 2 == 1) {
    // If either A or B is odd, there exists a C (either 1 or 3) that will make A * B * C odd
    printf("Yes\n");
  } else {
    // If both A and B are even, no C can make A * B * C odd
    printf("No\n");
  }

  return 0;
}