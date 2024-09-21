#include <stdio.h>

int main() {
  int S, h, m, s; // Declare variables for seconds, hours, minutes, and seconds

  scanf("%d", &S); // Read the input seconds from the user

  // Calculate hours, minutes, and seconds using integer division and modulo operations
  h = S / 3600;
  m = (S % 3600) / 60;
  s = (S % 3600) % 60;

  // Print the converted time in h:m:s format
  printf("%d:%d:%d\n", h, m, s);

  return 0; // Indicate successful program execution
}