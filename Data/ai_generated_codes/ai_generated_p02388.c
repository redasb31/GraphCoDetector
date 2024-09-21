#include <stdio.h>

int main() {
  // Declare variable to store the input integer
  int x;

  // Read the input integer from the user
  scanf("%d", &x);

  // Calculate the cube of the input integer
  int cube = x * x * x;

  // Print the calculated cube to the console
  printf("%d\n", cube);

  return 0;
}