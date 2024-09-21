#include <stdio.h>
#include <string.h>

int main() {
  // Declare a character array to store the input string.
  char S[21];

  // Read the input string from the user.
  scanf("%s", S);

  // Print the first three characters of the input string as the nickname.
  printf("%.*s\n", 3, S);

  return 0;
}