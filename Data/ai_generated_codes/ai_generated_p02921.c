#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables to store the forecast and actual weather strings.
  char S[4], T[4];

  // Read the forecast and actual weather strings from the input.
  scanf("%s", S);
  scanf("%s", T);

  // Initialize a variable to count the number of correct forecasts.
  int correct_days = 0;

  // Iterate over the characters in the strings to compare the forecast and actual weather for each day.
  for (int i = 0; i < 3; i++) {
    // If the forecast and actual weather match for a given day, increment the correct_days counter.
    if (S[i] == T[i]) {
      correct_days++;
    }
  }

  // Print the number of days for which the forecast was correct.
  printf("%d\n", correct_days);

  return 0;
}