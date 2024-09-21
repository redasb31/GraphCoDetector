#include <stdio.h>
#include <math.h>

int main() {
  // Declare variables to store the input integers
  int a, b;

  // Read the input integers from the user
  scanf("%d %d", &a, &b);

  // Calculate the average of the two integers
  double average = (double)(a + b) / 2;

  // Round the average up to the nearest integer using ceil() function
  int roundedAverage = ceil(average);

  // Print the rounded average
  printf("%d\n", roundedAverage);

  return 0;
}