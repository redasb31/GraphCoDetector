#include <stdio.h>

int main() {
  // M: Number of months in a year
  // D: Number of days in a month
  int M, D;

  // Read the number of months and days from the standard input
  scanf("%d %d", &M, &D);

  // Initialize the count of Product Days to 0
  int product_days = 0;

  // Iterate through all months
  for (int m = 1; m <= M; ++m) {
    // Iterate through all days
    for (int d = 1; d <= D; ++d) {
      // Extract the tens digit and ones digit of the day
      int d_10 = d / 10;
      int d_1 = d % 10;

      // Check if the day satisfies the conditions for a Product Day
      if (d_1 >= 2 && d_10 >= 2 && d_1 * d_10 == m) {
        // Increment the count of Product Days
        product_days++;
      }
    }
  }

  // Print the number of Product Days
  printf("%d\n", product_days);

  return 0;
}