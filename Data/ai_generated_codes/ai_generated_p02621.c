#include <stdio.h>

int main() {
  // Declare the variable 'a' to store the input integer.
  int a;

  // Read the input integer 'a' from the user.
  scanf("%d", &a);

  // Calculate the sum a + a^2 + a^3.
  int sum = a + a * a + a * a * a;

  // Print the calculated sum.
  printf("%d\n", sum);

  return 0;
}