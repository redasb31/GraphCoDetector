#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string variable to store the input string
  char S[7]; 

  // Read the input string from the user
  scanf("%s", S);

  // Check if the 3rd and 4th characters are equal and the 5th and 6th characters are equal
  if (S[2] == S[3] && S[4] == S[5]) {
    // If both conditions are met, print "Yes"
    printf("Yes\n");
  } else {
    // Otherwise, print "No"
    printf("No\n");
  }

  return 0;
}