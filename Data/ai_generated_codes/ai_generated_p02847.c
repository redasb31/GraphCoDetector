#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string variable to store the day of the week.
  char day[4];

  // Read the day of the week from the standard input.
  scanf("%s", day);

  // Calculate the number of days until the next Sunday.
  int days_until_sunday;
  if (strcmp(day, "SUN") == 0) {
    days_until_sunday = 7;
  } else if (strcmp(day, "MON") == 0) {
    days_until_sunday = 6;
  } else if (strcmp(day, "TUE") == 0) {
    days_until_sunday = 5;
  } else if (strcmp(day, "WED") == 0) {
    days_until_sunday = 4;
  } else if (strcmp(day, "THU") == 0) {
    days_until_sunday = 3;
  } else if (strcmp(day, "FRI") == 0) {
    days_until_sunday = 2;
  } else if (strcmp(day, "SAT") == 0) {
    days_until_sunday = 1;
  }

  // Print the number of days until the next Sunday.
  printf("%d\n", days_until_sunday);

  return 0;
}