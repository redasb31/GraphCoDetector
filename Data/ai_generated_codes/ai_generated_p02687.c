#include <stdio.h>
#include <string.h>

int main() {
  // Declare a character array to store the input string
  char S[4];

  // Read the input string from the user
  scanf("%s", S);

  // Check if the input string is "ABC"
  if (strcmp(S, "ABC") == 0) {
    // If it is, print "ARC"
    printf("ARC\n");
  } else {
    // Otherwise, print "ABC"
    printf("ABC\n");
  }

  return 0;
}