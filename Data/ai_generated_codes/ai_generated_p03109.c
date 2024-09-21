#include <stdio.h>
#include <string.h>

int main() {
  // Get the input string.
  char S[11];
  scanf("%s", S);

  // Extract the month and day from the input string.
  int month = (S[5] - '0') * 10 + (S[6] - '0');
  int day = (S[8] - '0') * 10 + (S[9] - '0');

  // Check if the date is before or on April 30, 2019.
  if (month < 4 || (month == 4 && day <= 30)) {
    printf("Heisei\n");
  } else {
    printf("TBD\n");
  }

  return 0;
}