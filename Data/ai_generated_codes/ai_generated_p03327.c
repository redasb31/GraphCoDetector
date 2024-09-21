#include <stdio.h>

int main() {
  // Declare an integer variable to store the input value.
  int N;

  // Read the input value from the standard input.
  scanf("%d", &N);

  // Check if the input value is less than or equal to 999.
  if (N <= 999) {
    // If the input value is less than or equal to 999, print "ABC".
    printf("ABC\n");
  } else {
    // If the input value is greater than 999, print "ABD".
    printf("ABD\n");
  }

  return 0;
}