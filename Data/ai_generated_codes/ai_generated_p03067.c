#include <stdio.h>

int main() {
  // Declare variables to store the house coordinates.
  int A, B, C;

  // Read the house coordinates from the standard input.
  scanf("%d %d %d", &A, &B, &C);

  // Check if House 3's coordinate lies between House 1 and House 2.
  if ((A < C && C < B) || (A > C && C > B)) {
    printf("Yes\n"); // If it does, print "Yes".
  } else {
    printf("No\n"); // Otherwise, print "No".
  }

  return 0;
}