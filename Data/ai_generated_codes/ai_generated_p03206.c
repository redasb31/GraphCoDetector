#include <stdio.h>

int main() {
  // Declare an integer variable 'd' to store the input day.
  int d;

  // Read the input day from the user.
  scanf("%d", &d);

  // Check the input day and print the corresponding message.
  if (d == 25) {
    printf("Christmas\n");
  } else if (d == 24) {
    printf("Christmas Eve\n");
  } else if (d == 23) {
    printf("Christmas Eve Eve\n");
  } else if (d == 22) {
    printf("Christmas Eve Eve Eve\n");
  }

  // Return 0 to indicate successful program execution.
  return 0;
}