#include <stdio.h>

int main() {
  int n, i, m, count;
  int A[1000000]; // Array to store the star colors

  while (1) {
    scanf("%d", &n); // Read the number of stars

    // Terminate the program if n is 0
    if (n == 0) {
      break;
    }

    // Read the star colors
    for (i = 0; i < n; i++) {
      scanf("%d", &A[i]);
    }

    m = -1; // Initialize the color with an invalid value
    count = 0; // Initialize the count of the color with 0

    // Iterate through the array to find the color with most occurrences
    for (i = 0; i < n; i++) {
      if (count < n / 2) { // Check if the current count is less than half of the total stars
        if (count == 0) {
          m = A[i]; // Set the initial color
        } else if (A[i] == m) {
          count++; // Increment the count if the color matches the current color
        } else {
          count = 1; // Reset the count and set the color if the color doesn't match
          m = A[i];
        }
      } else {
        break; // Break the loop if the count reaches half of the total stars
      }
    }

    // Check if the most occurring color is greater than half of the total stars
    if (count > n / 2) {
      printf("%d\n", m); // Print the color
    } else {
      printf("NO COLOR\n"); // Print "NO COLOR" if the count is not greater than half
    }
  }

  return 0;
}