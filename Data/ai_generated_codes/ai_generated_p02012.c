#include <stdio.h>

// Function to calculate the sum of a rectangular region in the multiplication table
int sum_region(int a, int b, int c, int d) {
  // Calculate the sum of the numbers in the rectangle
  return ((b * (b + 1) / 2) - ((a - 1) * a / 2)) * ((d * (d + 1) / 2) - ((c - 1) * c / 2));
}

int main() {
  int S; // The target sum of the rectangular region

  // Read the input from the user
  scanf("%d", &S);

  int count = 0; // Counter for the number of rectangular regions
  
  // Iterate over all possible rectangles
  for (int a = 1; a <= S; a++) {
    for (int b = a; b <= S; b++) {
      for (int c = 1; c <= S; c++) {
        for (int d = c; d <= S; d++) {
          // Check if the sum of the current rectangle is equal to S
          if (sum_region(a, b, c, d) == S) {
            count++; // Increment the counter if the sum is equal to S
          }
        }
      }
    }
  }

  // Print the number of rectangular regions whose summation is S
  printf("%d\n", count);

  return 0;
}