#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string variable to store the input string.
  char S[4]; 

  // Read the input string from the user.
  scanf("%s", S); 

  // Check the length of the input string.
  if (strlen(S) == 2) {
    // If the length is 2, print the string as is.
    printf("%s\n", S);
  } else if (strlen(S) == 3) {
    // If the length is 3, reverse the string and print it.
    printf("%c%c%c\n", S[2], S[1], S[0]);
  } 

  return 0;
}