#include <stdio.h>

int main() {
  // Declare variables for input integers
  int a, b;

  // Read input integers from the user
  scanf("%d %d", &a, &b);

  // Compare the integers and print the appropriate output
  if (a < b) {
    printf("a < b\n");
  } else if (a > b) {
    printf("a > b\n");
  } else {
    printf("a == b\n");
  }

  return 0;
}