#include <stdio.h>

int main() {
  // Declare a variable to store the input value K.
  int K;

  // Read the value of K from the standard input.
  scanf("%d", &K);

  // Loop K times.
  for (int i = 0; i < K; i++) {
    // Print the string "ACL" K times.
    printf("ACL");
  }

  // Print a new line character at the end.
  printf("\n");

  return 0;
}