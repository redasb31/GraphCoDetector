#include <stdio.h>

int main() {
  // Declare variables to store the three integers
  int num1, num2, num3;

  // Read the three integers from the user
  scanf("%d %d %d", &num1, &num2, &num3);

  // Sort the three integers in ascending order
  // There are many ways to sort three integers. 
  // Here's one using nested if statements.
  if (num1 > num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
  }
  if (num1 > num3) {
    int temp = num1;
    num1 = num3;
    num3 = temp;
  }
  if (num2 > num3) {
    int temp = num2;
    num2 = num3;
    num3 = temp;
  }

  // Print the sorted integers
  printf("%d %d %d\n", num1, num2, num3);

  return 0;
}