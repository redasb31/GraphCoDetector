#include <stdio.h>
#include <string.h>

int main() {
  char S[11]; // Declare a character array to store the input string
  scanf("%s", S); // Read the input string from standard input

  // Check if the string is a Hitachi string by comparing it to the concatenation of 'hi' with itself multiple times
  if (strcmp(S, "hi") == 0 || strcmp(S, "hihi") == 0 || strcmp(S, "hihihi") == 0 || strcmp(S, "hihihihi") == 0 || strcmp(S, "hihihihihi") == 0 || strcmp(S, "hihihihihihi") == 0 || strcmp(S, "hihihihihihihi") == 0 || strcmp(S, "hihihihihihihihi") == 0 || strcmp(S, "hihihihihihihihihi") == 0 || strcmp(S, "hihihihihihihihihihi") == 0) {
    printf("Yes\n"); // If the string is a Hitachi string, print "Yes"
  } else {
    printf("No\n"); // Otherwise, print "No"
  }

  return 0;
}