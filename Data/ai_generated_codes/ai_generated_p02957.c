#include <stdio.h>

int main() {
  // Declare variables to store the input integers A and B.
  int A, B;

  // Read the input values for A and B from the standard input.
  scanf("%d %d", &A, &B);

  // Calculate the integer K that satisfies the condition.
  // If A and B are distinct, K will be the midpoint between them.
  int K = (A + B) / 2;

  // Check if K satisfies the condition.
  if (abs(A - K) == abs(B - K)) {
    // If K satisfies the condition, print its value.
    printf("%d\n", K);
  } else {
    // If no integer satisfies the condition, print "IMPOSSIBLE".
    printf("IMPOSSIBLE\n");
  }

  return 0;
}