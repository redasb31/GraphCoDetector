#include <stdio.h>

int main() {
  // T: Number of test cases
  int T;
  scanf("%d", &T);

  // Iterate through each test case
  for (int t = 0; t < T; t++) {
    // A, B: Integers written on balls
    // X, Y: Number of balls with A and B respectively
    // C: The integer to check for divisibility
    int A, B, X, Y, C;
    scanf("%d %d %d %d %d", &A, &X, &B, &Y, &C);

    // Calculate the remainder of A and B when divided by C
    int remainderA = A % C;
    int remainderB = B % C;

    // If A and B leave the same remainder when divided by C,
    // we can form groups with all balls.
    if (remainderA == remainderB) {
      printf("%d\n", X + Y);
    } else {
      // Calculate the maximum number of groups that can be formed
      // by maximizing the number of groups with the same remainder
      int maxGroups = 0;
      if (remainderA == 0) {
        maxGroups = X;
      } else if (remainderB == 0) {
        maxGroups = Y;
      } else {
        // Find the maximum number of groups with the same remainder
        // by taking the maximum between X and Y
        maxGroups = (X > Y) ? X : Y;
      }
      printf("%d\n", maxGroups);
    }
  }

  return 0;
}