#include <stdio.h>

int main() {
  // Declare an integer variable x to store the input value
  int x;

  // Read the value of x from the standard input
  scanf("%d", &x);

  // Check if x is equal to 0 and print 1 if it is
  if (x == 0) {
    printf("1\n");
  } 
  // Otherwise, print 0
  else {
    printf("0\n");
  }

  return 0;
}