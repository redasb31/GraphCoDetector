#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables to store the input
  int a;
  char s[11]; // Maximum length of string is 10

  // Read the input
  scanf("%d\n", &a);
  scanf("%s", s);

  // Check if 'a' is less than 3200 and print the appropriate output
  if (a < 3200) {
    printf("red\n");
  } else {
    printf("%s\n", s);
  }

  return 0;
}