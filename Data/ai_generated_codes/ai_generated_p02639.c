#include <stdio.h>

int main() {
  // Declare variables to store the input values.
  int x1, x2, x3, x4, x5;

  // Read the input values from the user.
  scanf("%d %d %d %d %d", &x1, &x2, &x3, &x4, &x5);

  // Check each variable to see if it has been assigned 0.
  if (x1 == 0) {
    printf("1\n"); // If x1 is 0, print 1.
  } else if (x2 == 0) {
    printf("2\n"); // If x2 is 0, print 2.
  } else if (x3 == 0) {
    printf("3\n"); // If x3 is 0, print 3.
  } else if (x4 == 0) {
    printf("4\n"); // If x4 is 0, print 4.
  } else if (x5 == 0) {
    printf("5\n"); // If x5 is 0, print 5.
  }

  return 0;
}