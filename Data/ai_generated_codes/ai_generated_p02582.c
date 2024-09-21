#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string to store the weather records.
  char S[4];

  // Read the weather records from the input.
  scanf("%s", S);

  // Initialize a variable to store the maximum number of consecutive rainy days.
  int max_rainy_days = 0;

  // Initialize a variable to count the number of consecutive rainy days.
  int current_rainy_days = 0;

  // Iterate through the weather records.
  for (int i = 0; i < 3; i++) {
    // If the current day is rainy, increment the count of consecutive rainy days.
    if (S[i] == 'R') {
      current_rainy_days++;
    } else {
      // If the current day is sunny, reset the count of consecutive rainy days.
      current_rainy_days = 0;
    }

    // Update the maximum number of consecutive rainy days if the current count is higher.
    max_rainy_days = (current_rainy_days > max_rainy_days) ? current_rainy_days : max_rainy_days;
  }

  // Print the maximum number of consecutive rainy days.
  printf("%d\n", max_rainy_days);

  return 0;
}