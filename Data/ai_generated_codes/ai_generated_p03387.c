#include <stdio.h>

int main() {
  // Declare variables to store the input values
  int A, B, C;

  // Read the input values from the user
  scanf("%d %d %d", &A, &B, &C);

  // Calculate the total sum of the input values
  int sum = A + B + C;

  // Calculate the average of the input values
  int average = sum / 3;

  // Calculate the number of operations required to make all values equal to the average
  int operations = 0;
  operations += abs(A - average);
  operations += abs(B - average);
  operations += abs(C - average);

  // Print the minimum number of operations required
  printf("%d\n", operations / 2);

  return 0;
}