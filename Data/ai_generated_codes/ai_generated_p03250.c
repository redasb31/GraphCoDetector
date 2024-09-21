#include <stdio.h>

int main() {
  // Declare variables to store the values on the integer panels
  int A, B, C;

  // Read the values from the input
  scanf("%d %d %d", &A, &B, &C);

  // Calculate the maximum possible allowance by trying all possible arrangements
  int max_allowance = 0;
  max_allowance = (A * 10 + B) + C; // AB + C
  if ((A * 10 + C) + B > max_allowance) {
    max_allowance = (A * 10 + C) + B; // AC + B
  }
  if ((B * 10 + A) + C > max_allowance) {
    max_allowance = (B * 10 + A) + C; // BA + C
  }
  if ((B * 10 + C) + A > max_allowance) {
    max_allowance = (B * 10 + C) + A; // BC + A
  }
  if ((C * 10 + A) + B > max_allowance) {
    max_allowance = (C * 10 + A) + B; // CA + B
  }
  if ((C * 10 + B) + A > max_allowance) {
    max_allowance = (C * 10 + B) + A; // CB + A
  }

  // Print the maximum possible allowance
  printf("%d\n", max_allowance);

  return 0;
}