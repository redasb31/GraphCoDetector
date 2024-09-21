#include <stdio.h>

int main() {
  int n; // Number of days

  // Read the number of days until the input is 0
  while (scanf("%d", &n) != EOF && n != 0) {
    // Calculate the expected value
    double expectedValue = (double)n * 1.0 / 100; 

    // Print the expected value
    printf("%.8lf\n", expectedValue);
  }

  return 0;
}