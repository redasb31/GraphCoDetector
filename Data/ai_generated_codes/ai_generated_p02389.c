#include <stdio.h>

int main() {
  // Declare variables for length and breadth
  int a, b;

  // Read the length and breadth from the user
  scanf("%d %d", &a, &b);

  // Calculate the area of the rectangle
  int area = a * b;

  // Calculate the perimeter of the rectangle
  int perimeter = 2 * (a + b);

  // Print the area and perimeter
  printf("%d %d\n", area, perimeter);

  return 0;
}