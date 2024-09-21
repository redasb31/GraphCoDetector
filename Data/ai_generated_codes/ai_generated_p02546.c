#include <stdio.h>
#include <string.h>

int main() {
  char s[1001]; // Declare a string variable to store the input

  // Read the input string
  scanf("%s", s);

  // Check if the input string ends with 's'
  if (s[strlen(s) - 1] == 's') {
    // If it ends with 's', append 'es' to the end
    strcat(s, "es");
  } else {
    // If it doesn't end with 's', append 's' to the end
    strcat(s, "s");
  }

  // Print the plural form
  printf("%s\n", s);

  return 0;
}