#include <stdio.h>
#include <string.h>

int main() {
  char S[5]; // Declare a character array to store the input string

  scanf("%s", S); // Read the security code from the user

  // Iterate through the string, checking for consecutive digits
  for (int i = 0; i < 3; i++) {
    if (S[i] == S[i + 1]) { // If two consecutive digits are the same
      printf("Bad\n"); // Print "Bad" and exit the loop
      return 0;
    }
  }

  // If the loop completes without finding consecutive digits, print "Good"
  printf("Good\n");

  return 0;
}