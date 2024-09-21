#include <stdio.h>

int main() {
  int m, d;
  int days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}; // Days from Jan 1st to the end of each month
  char *weekday[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}; // Weekday names

  while (1) {
    scanf("%d %d", &m, &d); // Read month and day from input

    if (m == 0 && d == 0) { // Check for end of input
      break;
    }

    int totalDays = days[m - 1] + d; // Calculate total days from Jan 1st

    if (m > 2) { // Account for leap year after Feb
      totalDays++;
    }

    int dayIndex = (totalDays + 3) % 7; // Calculate day index (Jan 1st, 2004 was Thursday)

    printf("%s\n", weekday[dayIndex]); // Print the corresponding weekday
  }

  return 0;
}