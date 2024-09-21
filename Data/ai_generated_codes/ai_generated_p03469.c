#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string variable to store the input date
  char S[11];

  // Read the input string from the user
  scanf("%s", S);

  // Replace the first four characters with "2018"
  strcpy(S, "2018"); 
  // Concatenate the remaining part of the input string to S
  strcat(S, S + 4);

  // Print the modified date
  printf("%s\n", S);

  return 0;
}